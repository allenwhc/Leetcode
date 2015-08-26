import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class Solution {
	public static List<String> letterCombinations(String digits) {
        String[] keyboard={" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        List<String> combination=new ArrayList<String>();
        if(digits.length()==0) return combination;
        char[] cc=new char[digits.length()];
        for(int i=0; i<digits.length(); i++)
        	cc[i]=' ';
        dfs(combination, cc, keyboard, digits, 0);
        return combination;
    }
	
	public static void dfs(List<String> combination, char[] cc, String[] keyboard,  String digits, int index){
		if(index==digits.length()){
			combination.add(new String(cc));
			return;
		}
		for(int i=0; i<keyboard[digits.charAt(index)-'0'].length(); i++){
			cc[index]=keyboard[digits.charAt(index)-'0'].charAt(i);
			dfs(combination, cc, keyboard, digits, index+1);
		}
	}
	
	public static void main(String[] args){
		String digits="23";
		System.out.println("The input digits are: "+digits);
		System.out.println("All letter combinations are: "+Arrays.deepToString(letterCombinations(digits).toArray()));
	}
}
