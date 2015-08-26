import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	//Subsets I, array contains only distinct nums
	public static List<List<Integer>> subsets(int[] nums){
		Arrays.sort(nums);	//Sort the input array
		List<List<Integer>> allSubsets=new ArrayList<List<Integer>>();
		List<Integer> subset=new ArrayList<Integer>();
		allSubsets.add(subset);	//Add empty set
		generateSubsets1(nums, allSubsets, subset, 0);
		return allSubsets;
	}
	
	public static void generateSubsets1(int[] nums, List<List<Integer>> allSubsets, List<Integer> subset, int step){
		for(int i=step; i<nums.length; i++){
			subset.add(nums[i]);
			allSubsets.add(new ArrayList<Integer>(subset));
			generateSubsets1(nums, allSubsets, subset, i+1);
			subset.remove(subset.size()-1);
		}
	}
	
	//Subsets II, array may contain duplicate numbers
		public static List<List<Integer>> subsetsWithDup(int[] nums){
			Arrays.sort(nums);	//Sort the input array
			List<List<Integer>> allSubsets=new ArrayList<List<Integer>>();
			List<Integer> subset=new ArrayList<Integer>();
			allSubsets.add(subset);	//Add empty set
			generateSubsets2(nums, allSubsets, subset, 0);
			return allSubsets;
		}
		
		public static void generateSubsets2(int[] nums, List<List<Integer>> allSubsets, List<Integer> subset, int step){
			for(int i=step; i<nums.length; i++){
				subset.add(nums[i]);
				allSubsets.add(new ArrayList<Integer>(subset));
				generateSubsets2(nums, allSubsets, subset, i+1);
				subset.remove(subset.size()-1);
				while(i<nums.length-1 && nums[i]==nums[i+1]) ++i;
			}
		}
	
	//Main
	public static void main(String[] args){
		int[] nums1={4,2,1,3};
		int[] nums2={2,1,2};
		System.out.print("Array 1 (contains only distinct elements): ");
		for(int i=0; i<nums1.length; i++)
			System.out.print(nums1[i]+" ");
		System.out.println();
		System.out.println("All subsets are: ");
		for(List<Integer> ls:subsets(nums1))
			System.out.println(Arrays.deepToString(ls.toArray()));
		
		System.out.print("Array 2 (contains duplicate elements): ");
		for(int i=0; i<nums2.length; i++)
			System.out.print(nums2[i]+" ");
		System.out.println();
		System.out.println("All subsets are: ");
		for(List<Integer> ls:subsetsWithDup(nums2))
			System.out.println(Arrays.deepToString(ls.toArray()));
	}
}
