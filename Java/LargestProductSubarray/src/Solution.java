import java.util.Arrays;

public class Solution {
	public static int maxProduct(int[] nums){
		int n=nums.length;
		if(n==0) return 0;
		int[] max=new int[n];
		int[] min=new int[n];
		
		max[0]=min[0]=nums[0];
		for(int i=1; i<n; i++){
			max[i]=Math.max(max[i-1]*nums[i], Math.max(nums[i], min[i-1]*nums[i]));
			min[i]=Math.min(min[i-1]*nums[i], Math.min(nums[i], max[i-1]*nums[i]));
		}
		int maxPro=Integer.MIN_VALUE;
		for(int i=0; i<n; i++)
			maxPro=Math.max(maxPro, max[i]);
		return maxPro;
	}
	
	public static void main(String[] args){
		int[] nums={2,3,-2,4};
		System.out.println("The array is: "+Arrays.toString(nums));
		System.out.println("The maximum product is: "+maxProduct(nums));
	}
}
