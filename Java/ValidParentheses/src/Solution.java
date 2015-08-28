
import java.util.Stack;

public class Solution {
	public static boolean isValid(String s){
		int n=s.length();
		if(n==0) return true;
		if(n==1) return false;
		Stack<Character> stack=new Stack<>();
	//	stack.push(s.charAt(0));
		for(int i=0; i<n; i++){
			if(s.charAt(i)=='(' || s.charAt(i)=='[' || s.charAt(i)=='{'){
				stack.push(s.charAt(i));
				continue;
			}
			//System.out.println(s.charAt(i)+","+stack.peek());
			if(stack.isEmpty() || (s.charAt(i)==')' && stack.pop()!='(') || (s.charAt(i)==']' && stack.pop()!='[') ||(s.charAt(i)=='}' && stack.pop()!='{'))
				return false;
		}
		if(!stack.isEmpty()) return false;
		return true;
	}
	
	public static void main(String[] args){
		String s="((";
		if(isValid(s))
			System.out.println("'"+s+"' is a valid set of parentheses.");
		else
			System.out.println("'"+s+"' is not a valid set of parentheses.");
	}
}
