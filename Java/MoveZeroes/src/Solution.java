import java.util.Arrays;

public class Solution {
	public static void moveZeroes(int[] nums){
		int n=nums.length;
		if(n<=1) return;
		int i=0,j=0;
		while(i<n){
			if(nums[i]!=0){
				int temp=nums[i];
				nums[i]=nums[j];
				nums[j]=temp;
				i++;
				j++;
			}
			else{
				i++;
			}
		}
	}
	
	public static void main(String[] args) {
		int[] nums={0,1,0,3,12};
		System.out.println("The original array is: "+Arrays.toString(nums));
		moveZeroes(nums);
		System.out.println("The moved array is: "+Arrays.toString(nums));
	}
}
