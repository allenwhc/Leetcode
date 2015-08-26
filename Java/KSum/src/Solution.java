import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	public static List<List<Integer>> KSum(int[] nums, int target, int k){
		List<List<Integer>> allSols=new ArrayList<List<Integer>>();
		List<Integer> sol=new ArrayList<Integer>();
		Arrays.sort(nums);
		iterateKSum(0, nums.length-1, target, k, nums, sol, allSols);
		return allSols;
	}
	
	//Reduce order from k to k-1
	private static void iterateKSum(int start, int end, int target, int k, int[] nums, List<Integer> sol, List<List<Integer>> allSols){
		if(k<=0) return;
		if(k==1){
			for(int i=start; i<=end; i++){
				if(nums[i]==target){
					sol.add(nums[i]);
					allSols.add(sol);
					sol.remove(sol.size()-1);
				}
			}
		}
		if(k==2){
			twoSum(start, end, target, nums, sol, allSols);
			return;
		}
		for(int i=start; i<=end-k+1; i++){
			if(i>start&&nums[i]==nums[i-1]) continue;
			sol.add(nums[i]);
			iterateKSum(i+1, end, target-nums[i], k-1, nums, sol, allSols);
			sol.remove(sol.size()-1);
		}
		
	}
	
	//Get Two Sum
	private static void twoSum(int start, int end, int target, int[] nums, List<Integer> sol, List<List<Integer>> allSols){
		while(start<end){
			int sum=nums[start]+nums[end];
			if(sum==target){
				sol.add(nums[start]);
				sol.add(nums[end]);
				allSols.add(new ArrayList<Integer>(sol));
				sol.remove(sol.size()-1);
				sol.remove(sol.size()-1);
				start++;
				end--;
				//Skips duplicate elements
				while(nums[start]==nums[start-1]) start++;	
				while(nums[end]==nums[end+1]) end--;
			}
			else if(sum<target) start++;
			else end--;
		}
	}
	
	//Main
	public static void main(String[] args){
		int[] nums={-1,0,0,-2,1,2,-1,-4};
		int target=0;
		int k=3;
		System.out.println("The solutions adding up to "+target+" with "+k+" numbers in array "+Arrays.toString(nums)+" are: ");
		for(List<Integer> ls:KSum(nums, target, k))
			System.out.println(Arrays.deepToString(ls.toArray()));
	}
}
