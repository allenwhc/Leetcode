import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	public static List<String> generateParenthesis(int n){
		List<String> result=new ArrayList<>();
		StringBuffer str=new StringBuffer();
		if(n==0) return result;
		add(result, str, n, 0, 0, 0);
		return result;
	}
	
	private static void add(List<String> result, StringBuffer str, int n, int step, int left, int right){
		if(step==n*2){
			result.add(str.toString());
			return;
		}
		
		if(left<n){
			str.append('(');
			add(result, str, n, step+1, left+1, right);
			str.setLength(str.length()-1);
		}
		
		if(left>right){
			str.append(')');
			add(result, str, n, step+1, left, right+1);
			str.setLength(str.length()-1);
		}
	}
	
	public static void main(String[] args) {
		int n=3;
		System.out.println("Parenthesis are: "+Arrays.deepToString(generateParenthesis(n).toArray()));
	}
}
