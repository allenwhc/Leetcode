import java.util.Arrays;
import java.util.HashMap;

public class Solution {
	public static int longestConsecutive(int[] nums) {
        int n=nums.length;
        if(n==0) return 0;
        int maxLen=0;
        HashMap<Integer, Integer> hmap=new HashMap<>();
        for(int i=0; i<n; i++){
        	hmap.put(nums[i], i);
        }
        int len;
        for(int i=0; i<n; i++){
        	len=1;	//Reset len
        	hmap.remove(nums[i]);
        	
        	//Check curr--
        	int curr=nums[i]-1;	
        	while(hmap.containsKey(curr)){
        		hmap.remove(curr);
        		curr--;
        		len++;
        	}
        	//Check curr++
        	curr=nums[i]+1;
        	while(hmap.containsKey(curr)){
        		hmap.remove(curr);
        		curr++;
        		len++;
        	}
        	
        	maxLen=Math.max(maxLen, len);
        }
        return maxLen;
    }
	
	public static void main(String[] args) {
		int[] nums={1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
		System.out.println("The array is:"+Arrays.toString(nums));
		System.out.println("The length of longest consecutive sequence is: "+longestConsecutive(nums));
	}
}
