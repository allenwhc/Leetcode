//import java.util.Map.Entry;
import java.util.HashMap;

public class Solution {
	public static int lengthOfLongestSubstringTwoDistinct(String s) {
        int n=s.length();
        HashMap<Character, Integer> map=new HashMap<>();
        int max_len=0;
        int left=0;
        for(int i=0; i<n; i++){
        	char c=s.charAt(i);
        	if(map.size()==2 && !map.containsKey(c)){
        		max_len=Math.max(max_len, i-left);
        		
        		int leftMost=n+1;
        		for(Character key:map.keySet())
        			leftMost=Math.min(leftMost, map.get(key));
        		left=leftMost+1;
        		map.remove(s.charAt(leftMost));
        	}
        	map.put(c, i);
        }
        if(!map.isEmpty() && max_len==0)
        	return n;
        if(map.size()==2)
        	max_len=Math.max(max_len, n-left);
        return max_len;
    }
	
	public static void main(String[] args) {
		String s="cdaba";
		System.out.println("Length of longest substring with at most two distinct characters in '"+s+"' is: "+lengthOfLongestSubstringTwoDistinct(s));
	}
}
