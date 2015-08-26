import java.util.Arrays;

public class Solution {
	public static void nextPermutation(int[] nums) {
        int n=nums.length;
        if(n<=1) return;
		int i=n-1;
		while(i>0 && nums[i-1]>=nums[i]) i--;
		int j=n-1;
		if(i<=0){
			while(i<j){
				swap(nums, i, j);
				i++;
				j--;
				
			}
			return;
		}
		while(nums[j]<=nums[i-1]) j--;
		swap(nums, i-1, j);
		j=n-1;
		while(i<j){
			swap(nums, i, j);
			i++;
			j--;
			
		}
    }
	
	public static void swap(int[] nums, int i, int j){
		int temp=nums[i];
		nums[i]=nums[j];
		nums[j]=temp;
	}
	
	public static void main(String[] args) {
		int[][] nums={{4,3,2,1},{3,2,4,1},{1,1,7,5}}; 
		for(int[] n:nums){
			System.out.print("The next permutation of: "+Arrays.toString(n));
			nextPermutation(n);
			System.out.println(" is: "+Arrays.toString(n));
		}
	}
}
