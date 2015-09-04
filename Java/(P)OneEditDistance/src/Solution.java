
public class Solution {
	public static boolean isOneEditDistance(String s, String t) {
        int m=s.length();
        int n=t.length();
        for(int i=0; i<Math.min(m, n); i++){
        	if(s.charAt(i)!=t.charAt(i))
        		return s.substring(i+(m>=n?1:0)).equals(t.substring(i+(n>=m?1:0)));
        }
        return Math.abs(m-n)==1;
    }
	
	public static void main(String[] args) {
		String s="ab";
		String t="ac";
		if(isOneEditDistance(s, t))
			System.out.println("'"+s+"' and '"+t+"' are one edit distance apart");
		else
			System.out.println("'"+s+"' and '"+t+"' aren't one edit distance apart");
	}
}