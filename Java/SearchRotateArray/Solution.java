import java.util.Arrays;

public class Solution{
	public static int search(int[] nums, int target){
		if(nums.length==0) return -1;

		int start=0; 
		int end=nums.length-1;
		while(start<=end){
			int mid=(end-start)/2+start;
			if(nums[mid]==target) return mid;
			else if(nums[mid]>=nums[start]){
				if(target>=nums[start] && target<nums[mid])
					end=mid-1;
				else 
					start=mid+1;
			}
			else{
				if(target>nums[mid] && target<=nums[end])
					start=mid+1;
				else 
					end=mid-1;
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		int[] nums={5,6,7,0,1,2,4};
		int target=1;
		System.out.println("The index of "+target+" in "+Arrays.toString(nums)+" is: "+search(nums,target));
	}
}