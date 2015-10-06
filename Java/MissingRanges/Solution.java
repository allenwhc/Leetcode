import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class Solution{
	public static List<String> findMissingRanges(int[] nums, int lower, int upper){
		int n=nums.length;
		List<String> ranges=new ArrayList<String>();
		if(n==0){
			ranges.add(addRange(lower,upper));
			return ranges;
		}

		int prev=0;
		if(lower<nums[0]){
			ranges.add(addRange(lower, nums[0]-1));
			prev=nums[0];
		}
		else
			prev=lower;

		for(int i=0; i<n; i++){
			if(nums[i]>prev+1){
				ranges.add(addRange(prev+1, nums[i]-1));
			}
			prev=nums[i];
		}
		if(upper>prev)
			ranges.add(addRange(prev+1,upper));
		return ranges;
	}

	private static String addRange(int lower, int upper){
		return (lower==upper)?String.valueOf(lower):lower+"->"+upper;
	}

	public static void main(String[] args) {
		int[] nums={0,1,3,50,75};
		int lower=-10;
		int upper=99;
		System.out.println("The missing ranges from "+lower+"-"+upper+" is: "+Arrays.deepToString(findMissingRanges(nums,lower,upper).toArray()));
	}
}