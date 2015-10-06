import java.util.Arrays;

public class Solution{
	public static void sortColors(int[] nums){
		int n=nums.length;
		if(n<=1) return;
		int j=0;
		int prev=0;
		for(int i=0; i<n-1; i++){
			j++;
			if(j<n){
				i=prev;
			}
			else
				j=i+1;
			if(nums[i]>nums[j]){
				int temp=nums[i];
				nums[i]=nums[j];
				nums[j]=temp;
			}
			prev=i;
		}

	}

	public static void main(String[] args) {
		int[] nums={0,2,2,1,0,2,2,0,1,1,0,2};
		System.out.println("The unsorted color array is: "+Arrays.toString(nums));
		sortColors(nums);
		System.out.println("The sorted color array is: "+Arrays.toString(nums));
	}
}