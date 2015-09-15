import java.util.HashMap;

public class Solution {
	public static String minWindow(String s, String t){
		int m=s.length();
		int n=t.length();
		if((m==0) || (n==0) || (m<n) ||(m==n && !s.equals(t))) return "";
		String result=new String();
		HashMap<Character, Integer> charS=new HashMap<>();
		HashMap<Character, Integer> charT=new HashMap<>();
		
		//Count characters' appearance in t
		for(int i=0; i<n; i++){
			char c=t.charAt(i);
			if(!charT.containsKey(c))
				charT.put(c, 1);
			else
				charT.put(c, charT.get(c)+1);
		}
		
		
		
		int count=0;
		int min_len=m+1;
		int left=0;
		for(int i=0; i<m; i++){
			char c=s.charAt(i);
			if(charT.containsKey(c)){
				if(charS.containsKey(c)){
					if(charS.get(c)<charT.get(c))
						count++;
					charS.put(c, charS.get(c)+1);
				}
				else{
					count++;
					charS.put(c, 1);
				}
			}

			if(count==n){
				char cLeft=s.charAt(left);
				while(!charT.containsKey(cLeft) || charT.get(cLeft)<charS.get(cLeft)){
					if(charS.containsKey(cLeft) && charT.get(cLeft)<charS.get(cLeft))
						charS.put(cLeft,charS.get(cLeft)-1);
					cLeft=s.charAt(++left);
				}
				if(i-left+1<min_len){
					min_len=i-left+1;
					result=s.substring(left, i+1);
				}
			}
		}
		return result;
	}
	
	public static void main(String[] args) {
		String s="ADOBECODEBANC";
		String t="ABC";
		System.out.println("The minimum window in '"+s+"' containing '"+t+"' is: '"+minWindow(s, t)+"'.");
	}
}