import java.util.Arrays;

public class Solution {
	public static int minSubArrayLen(int s, int[] nums) {
        int n=nums.length;
        if(n==0) return 0;
        int start=0, end=0;
        int minLen=n+1;
        int sum=0;
        for(int i:nums)
        	sum+=i;
        if(sum<s) return 0;
        sum=0;
        while(end<n){
        	while(sum<s && end<n){
        		sum+=nums[end++];
        	}
        	while(sum>=s && start<n){
        		minLen=Math.min(minLen, end-start);
        		sum-=nums[start++];
        	}
        }
        return minLen;
    }
	
	public static void main(String[] args) {
		int[] nums={2,3,1,2,4,3};
		System.out.println("The array is: "+Arrays.toString(nums));
		int s=7;
		System.out.println("The minimal length that the sum is greater than or equal to "+s+" is: "+minSubArrayLen(s, nums));
	}
}
