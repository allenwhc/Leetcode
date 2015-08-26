import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	public static List<List<Integer>> combine(int n, int k){
		List<List<Integer>> result=new ArrayList<List<Integer>>();
		if(n<=0 || n<k) return result;
		int[] nums=new int[n];
		for(int i=0; i<n; i++) nums[i]=i+1;
		List<Integer> com=new ArrayList<Integer>();
		generateCombination(nums, 0, k, com, result);
		return result;
	}
	
	private static void generateCombination(int[] nums, int start, int k, List<Integer> com, List<List<Integer>> result){
		if(com.size()==k){
			result.add(new ArrayList<Integer>(com));
			return;
		}
		
		for(int i=start; i<nums.length; i++){
			com.add(nums[i]);
			generateCombination(nums, i+1, k, com, result);
			com.remove(com.size()-1);
		}
	}
	
	public static void main(String[] args){
		int n=5;
		int k=3;
		System.out.println("The combination of ("+n+","+k+") are:");
		for(List<Integer> arr:combine(n, k)){
			System.out.println(Arrays.deepToString(arr.toArray())+",");
		}
	}
}

