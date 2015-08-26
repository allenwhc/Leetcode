
public class Solution {
	public static boolean isScramble(String s1, String s2) {
        if(s1.length()!=s2.length()) return false;
        if(s1.equals(s2)) return true;
        int len=s1.length();
        
        //Check if s1, s2 has the same letter combination
        int sum1=0,sum2=0;
        for(int i=0; i<len; i++){
        	sum1+=s1.charAt(i)-'a';
        	sum2+=s2.charAt(i)-'a';
        }
        if(sum1!=sum2) return false;
        
        for(int i=1; i<len; i++){ 
        	if(isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i)))
        		return true;
        	if(isScramble(s1.substring(0, i), s2.substring(len-i)) && isScramble(s1.substring(i), s2.substring(0, len-i)))
        		return true;
        }
        
        return false;
    }
	
	public static void main(String[] args){
		String s1="great";
		String s2="taerg";
		if(isScramble(s1, s2))
			System.out.println("'"+s1+"' is a scrambled string of '"+s2+"'");
		else
			System.out.println("'"+s1+"' is not a scrambled string of '"+s2+"'");
	}
}
