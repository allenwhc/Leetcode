import java.util.Arrays;

public class Solution {
	public static int maxSubArray(int[] nums) {
        int n=nums.length;
        if(n==0) return 0;
        int sum=0;
        int result=Integer.MIN_VALUE;
        for(int i=0; i<n; i++){
        	sum+=nums[i];
        	result=Math.max(result, sum);
        	sum=Math.max(0, sum);
        }
        return result;
    }
	
	public static void main(String[] args) {
		int[] nums={-2,1,-3,4,-1,2,1,-5,4};
		System.out.println("The input array is: "+Arrays.toString(nums));
		System.out.println("Maximum subarray sum is: "+maxSubArray(nums));
	}
}
