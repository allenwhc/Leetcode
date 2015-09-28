import java.util.Arrays;

public class Solution {
	public static int findDuplicate(int[] nums){
		int n=nums.length;
		if(n<=1) return 0;
		int duplicate=0;
		for(int i=0; i<n; i++){
			if(nums[Math.abs(nums[i])]>0)
				nums[Math.abs(nums[i])]=-nums[Math.abs(nums[i])];
			else {
				duplicate=Math.abs(nums[i]);
				break;
			}
		}
		return duplicate;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums={2,2,2,2,2,2};
		System.out.println("The array is: "+Arrays.toString(nums));
		System.out.println("The duplicate number is: "+findDuplicate(nums));
	}

}
