import java.util.HashMap;

public class Solution {
    public static int lengthOfLongestSubstring(String s) {
        int n=s.length();
        boolean[] charExist=new boolean[256];
        for(int i=0; i<256; i++)
        	charExist[i]=false;
        int max_len=0;
        int i=0, j=0;
        while(i<n){
        	if(charExist[s.charAt(i)]){
        		max_len=Math.max(max_len, i-j);
        		while(s.charAt(i)!=s.charAt(j)){
        			charExist[s.charAt(j)]=false;
        			j++;
        		}
        		i++;
        		j++;
        	}
        	else{
        		charExist[s.charAt(i)]=true;
        		i++;
        	}
        }
        max_len=Math.max(n-j, max_len);
        return max_len;
    }
    
    public static void main(String[] args) {
		String s="au";
		System.out.println("Length of longest non-repeating-character substring in '"+s+"' is: "+lengthOfLongestSubstring(s));
	}
}
