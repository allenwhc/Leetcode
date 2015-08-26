import java.util.Arrays;
import java.util.HashMap;

public class Solution {
    public static int firstMissingPositive(int[] nums) {
        int n=nums.length;
        if(n==0) return 1;
        //Move all negative numbers to left side of array
        int j=0;
        for(int i=0; i<n; i++){
        	if(nums[i]<=0){
        		swap(nums, i, j);
        		j++;
        	}
        }
      //  System.out.println("The array is: "+Arrays.toString(nums));
        for(int i=j; i<n; i++){
        	if(Math.abs(nums[i])<n-j && nums[Math.abs(nums[i])-1+j]>0)
        		nums[Math.abs(nums[i])-1+j]=-nums[Math.abs(nums[i])-1+j];
        }
        for(int i=j; i<n; i++)
        	if(nums[i]>0)
        		return i+1-j;
        return n-j+1;
    }
    
    public static void swap(int[] nums, int i, int j) {
		int temp=nums[i];
		nums[i]=nums[j];
		nums[j]=temp;
	}
    
    public static void main(String[] args) {
		int[] nums={-2,0,1,-3,2,4,-1};
		//int[] nums={1,2,0};
		System.out.println("The array is: "+Arrays.toString(nums));
		System.out.println("The first missing positive number is: "+firstMissingPositive(nums));
	}
}
