import java.util.Arrays;

public class Solution {
	public static void wiggleSort(int[] nums) {
        int n=nums.length;
        if(n<=1) return;
        boolean flag=true;
        int curr=nums[0];
        for(int i=0; i<n-1; i++){
        	if((flag && curr>nums[i+1]) || (!flag && curr<nums[i+1]))
        		nums[i]=nums[i+1];
        	else{
        		nums[i]=curr;
        		curr=nums[i+1];
        	}
        	flag=!flag;
        }
        nums[n-1]=curr;
        return;
    }
	
	public static void main(String[] args) {
		int[] nums={3,5,2,1,6,4};
		System.out.println("The input unsorted array is: "+Arrays.toString(nums));
		wiggleSort(nums);
		System.out.println("The wiggle-sorted array is: "+Arrays.toString(nums));
	}
}
