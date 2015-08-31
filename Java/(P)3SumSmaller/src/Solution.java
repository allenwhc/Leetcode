import java.util.Arrays;

public class Solution {
	public static int threeSumSmaller(int[] nums, int target){
		Arrays.sort(nums);
		int n=nums.length;
		if(n==0) return 0;
		int count=0;
		for(int i=0; i<n-2; i++){
			if(nums[i]+nums[i+1]+nums[i+2]>=target) break;
			int j=i+1;
			int k=n-1;;
			while(j<k){
				while(j<k && nums[i]+nums[j]+nums[k]>=target) k--;
				count+=k-j;
				j++;
			}
		}
		return count;
	}
	
	public static void main(String[] args){
		int[] nums={-1,1,-1,-1};
		int target=-1;
		System.out.println("The input array is: "+Arrays.toString(nums));
		System.out.println("The number of triplets whose sum is less than "+target+" is: "+threeSumSmaller(nums, target));
	}
}
