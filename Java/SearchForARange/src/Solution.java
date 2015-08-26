import java.util.Arrays;

public class Solution {
	public static int[] searchRange(int[] nums, int target) {
        int n=nums.length;
        int[] range=new int[2];
    	range[0]=-1;
    	range[1]=-1;
        if(n==0) return range;
        int start=0;
        int end=n-1;
        int left=-1, right=-1;
        while(start<=end){
        	int middle=(start+end)/2;
        	if(nums[middle]==target){
        		left=middle;
        		right=middle;
        		while(left>0 && nums[left]==nums[left-1]) left--;
        		while(right<n-1 && nums[right]==nums[right+1]) right++;
        		break;
        	}
        	else{
        		if(nums[middle]<target)
        			start=middle+1;
        		else
        			end=middle-1;
        	}
        }
        range[0]=left;
        range[1]=right;
        return range;
    }
	public static void main(String[] args){
		//int[] nums={2,5,6,6,7,7,9,10};
		int[] nums={1};
		int target=1;
		System.out.println("The sorted array is: "+Arrays.toString(nums));
		System.out.println("The range of "+target+" in above array is: "+Arrays.toString(searchRange(nums, target)));
	}
}
