import java.math.*;
public class Solution {
	public static String longestPalindrome(String s) {
		String ret=addBoundary(s);
		
		int n=ret.length();
		int[] P=new int[n];
		int center=0, rightMost=0;
		for(int i=1; i<n-1; i++){
			int i_mirror=2*center-i;
			P[i]=(rightMost>i)? (Math.min(P[i_mirror], rightMost-i)):0;
			while(ret.charAt(i+1+P[i])==ret.charAt(i-1-P[i])) P[i]++;
			if(i+P[i]>rightMost){
				center=i;
				rightMost=i+P[i];
			}
		}
		
		int centerIndex=0, maxLength=0;
		for(int i=1; i<n-1; i++){
			if(P[i]>maxLength){
				maxLength=P[i];
				centerIndex=i;
			}
		}
		//System.out.println(centerIndex+" , "+maxLength);
		return s.substring(centerIndex-maxLength-1,centerIndex/2);
	}
	
	public static String addBoundary(String s){
		int n=s.length();
		if(n==0 || s==null) return "^$";
		String s2="^";
		for(int i=0; i<n; i++){
			s2+="|"+s.substring(i,i+1);
			
		}
		s2+="|$";
		return s2;
	}
	
	public static void main(String[] args){
		String s=new String("bananas");
		String palin=longestPalindrome(s);
		System.out.print("The longest palindrome substring in "+s+" is: "+palin);
	}
}
