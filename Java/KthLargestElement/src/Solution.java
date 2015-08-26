import java.util.Arrays;

public class Solution {
	public static int findKthLargest(int[] nums, int k){
		if(nums.length==0 || nums==null) return -1;
		
	}
	public static void main(String[] args){
		int[] nums={3,2,1,5,6,4};
		int k=2;
		System.out.println("The array is: "+Arrays.toString(nums));
		System.out.println("The "+k+"th largest element is "+findKthLargest(nums, k));
	}
}
