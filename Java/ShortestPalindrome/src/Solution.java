
public class Solution {
	public static String shortestPalindrome(String s) {
        String rev_s=new StringBuffer(s).reverse().toString();
        String str=s+"#"+rev_s;
        int n=str.length();
        int[] palindrome=new int[n];
        for(int i=1; i<n-1; i++){
        	int j=palindrome[i-1];
        	if(palindrome[i]==palindrome[j]) j++;
        }
        return str;
        
    }
	
	public static void main(String[] args) {
		String s="aacecaaa";
		System.out.println("The shortest palindrome string of "+s+" is: "+shortestPalindrome(s));
	}
}
