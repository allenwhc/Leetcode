import java.lang.StringBuilder;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class Solution{
	private static String[] keys={" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

	public static List<String> letterCombinations(String digits){
		List<String> combinations=new ArrayList<String>();
		if(digits.length()==0) return combinations;
		StringBuilder sequence=new StringBuilder();
		sequence.setLength(digits.length());
		getCombinations(combinations,sequence,digits,0);
		return combinations;
	}

	private static void getCombinations(List<String> combinations, StringBuilder sequence, String digits, int idx){
		if(idx==digits.length()){
			combinations.add(sequence.toString());
			return;
		}

		for(int i=0; i<keys[digits.charAt(idx)-'0'].length(); i++){
			sequence.setCharAt(idx,keys[digits.charAt(idx)-'0'].charAt(i));
			getCombinations(combinations,sequence,digits,idx+1);
		}
	}

	public static void main(String[] args){
		String digits="23";
		System.out.println("The letter combinations of '"+digits+"' are: "+Arrays.deepToString(letterCombinations(digits).toArray()));
	}
}