import java.util.Arrays;

public class Solution {
	//Jump Game I, determine if one is able to reach the last index
	public static boolean canJump(int[] nums){
		int n=nums.length;
		if(n<=0) return false;
		if(n==1) return true;
		int currentIndex=0;
		for(int i=0; i<n; i++){
			if(i<=currentIndex) currentIndex=Math.max(currentIndex, i+nums[i]);
			if(currentIndex>=n-1) return true;
		}
		return false;
	}
	
	//Jump Game II, find the minimum number of jumps to reach the last index
	public static int jump(int[] nums){
		int n=nums.length;
		if(n<=1) return 0;
		int start=0, count=0, currentIndex=0;
		while(start<n){
			currentIndex=Math.max(currentIndex, nums[start]+start);
			if(currentIndex>0) count++;
			if(currentIndex>=n-1) return count;
			int temp=0;
			for(int j=start+1; j<=currentIndex; j++){
				if(nums[j]+j>temp){
					start=j;
					temp=nums[j]+j;
				}
			}
			
		}
		return count;
	}
	
	//Main
	public static void main(String[] args){
		int[] nums={2,0,1,1,4};
		//int[] nums={3,2,1,0,4};
		if(canJump(nums))
		{
			System.out.println("Can jump to the last index in "+Arrays.toString(nums));
			System.out.println("The minimum number of jumps is: "+jump(nums));
		}
		else 
			System.out.println("Can't jump to the last index in "+Arrays.toString(nums));
		
	}
}
