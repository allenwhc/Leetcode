import java.util.Arrays;

public class Solution {
	public static int[] twoSum(int[] nums, int target){
		int[] index=new int[2];
		int n=nums.length;
		if(n<2) return index;
		int i=0, j=n-1;
		while(i<j){
			int sum=nums[i]+nums[j];
			if(sum==target){
				index[0]=i+1;
				index[1]=j+1;
				break;
			}
			else if(sum>target) j--;
			else i++;
		}
		return index;
	}
	
	public static void main(String[] args){
		int[] nums={2,7,11,15};
		int target=13;
		System.out.println("The "+twoSum(nums, target)[0]+"th and "+twoSum(nums, target)[1]+"th number in "+Arrays.toString(nums)+" add up to "+target);
	}
}
