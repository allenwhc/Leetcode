
public class Solution {
	public static boolean isMatch(String s, String p) {
        int i=0, j=0;
        int star=-1, sMark=-1;	//position of '*' and s[i]
        while(i<s.length()){
        	if(j<p.length() && (p.charAt(j)=='?' || s.charAt(i)==p.charAt(j))){
        		i++;
        		j++;
        	}
        	else if(j<p.length() && p.charAt(j)=='*'){
        		star=j;
        		sMark=i;
        		j++;
        	}
        	else if (star!=-1) {
				j=star+1;
				i=++sMark;
			}
        	else return false;
        }
        while(j<p.length() && p.charAt(j)=='*') j++;
        return j==p.length();
    }
	
	public static void main(String[] args) {
		String[] s={"aa","aa","aaa","aa","aa","ab","aab"};
		String[] p={"a","aa","aa","*","a*","?*","c*a*b"};
		boolean[] isMathched=new boolean[s.length];
		for(int i=0; i<s.length; i++){
			isMathched[i]=isMatch(s[i], p[i]);
			if(isMathched[i])
				System.out.println("'"+s[i]+"' and '"+p[i]+"' are matched.");
			else
				System.out.println("'"+s[i]+"' and '"+p[i]+"' aren't matched.");
		}
	}
}
