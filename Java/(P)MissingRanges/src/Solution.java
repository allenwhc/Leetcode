import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	public static List<String> findMissingRanges(int[] nums, int lower, int upper){
		List<String> range=new ArrayList<>(); 
		int n=nums.length;
		if(n==0){
			range.add(output(lower, upper));
			return range;
		}
		int prev=0;
		
		//Determine if the first value is within (lower,upper)
		if(nums[0]>lower){
			range.add(output(lower, nums[0]-1));
			prev=nums[0];
		}
		else
			prev=lower;
		
		for(int i=0; i<n; i++){
			if(nums[i]-prev>1)
				range.add(output(prev+1, nums[i]-1));
			prev=nums[i];
		}
		if(upper>prev)
			range.add(output(prev+1, upper));
		return range;
	}
	
	private static String output(int start, int end){
		return (start==end)?String.valueOf(start):start+"->"+end;
	}
	
	public static void main(String[] args){
		int lower=0;
		int upper=99;
		int[] nums={0,1,3,50,75};
		System.out.println("The missing range from "+lower+" to "+upper+" in "+Arrays.toString(nums)+" is: "+Arrays.deepToString(findMissingRanges(nums, lower, upper).toArray()));
	}
}
