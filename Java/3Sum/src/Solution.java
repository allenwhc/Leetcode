import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	public static List<List<Integer>> threeSum(int[] nums) {
		int n=nums.length;
		Arrays.sort(nums);
		List<List<Integer>> allSols=new ArrayList<List<Integer>>();
		List<Integer> sol=new ArrayList<Integer>();
		if(n==0) return allSols;
		for(int i=0; i<n-2; i++){
			if(i==0 || nums[i]>nums[i-1]){	//Skip duplicate elements
				int j=i+1;
				int k=n-1;
				while(j<k){
					sol.clear();
					int sum=nums[i]+nums[j]+nums[k];
					if(sum==0){
						sol.add(nums[i]);
						sol.add(nums[j]);
						sol.add(nums[k]);
						allSols.add(new ArrayList<Integer>(sol));
						j++;
						k--;
						while(j<k && nums[j]==nums[j-1]) j++;
						while(j<k && nums[k]==nums[k+1]) k--;
						//break;
					}
					else{
						if(sum>0) k--;
						else j++;
					
					}
				}
			}
		}
		return allSols;
		
    }
	public static void main(String[] args){
		//int[] nums={-1,0,1,2,-1,-4};
		int[] nums={0,0,0,0};
		System.out.println("The array is: "+Arrays.toString(nums));
		for(List<Integer> arr:threeSum(nums))
			System.out.println(Arrays.deepToString(arr.toArray()));
	}
} 
