
public class Solution {
	public static String reverseWord(String s){
		if(s.length()==0) return "";
		StringBuffer result=new StringBuffer("");
		String[] splited=s.split("\\s+");
		for(int i=splited.length-1; i>=0; i--){
			result.append(splited[i]);
			result.append(" ");
		}
		
		//Delete trailing spaces
		if(result.length()>0){
			int i=result.length()-1;
			while(result.charAt(i)==' '){
				result.deleteCharAt(i);
				i--;
			}
		}
		return result.toString();
	}
	
	public static void main(String[] args){
		String s="Given a dictionary with set of words in it. Write a program to group all words which are anagrams of each other in to sets";
		System.out.println("The original string is: "+s);
		System.out.println("The reversed string is: "+reverseWord(s));
	}
}
