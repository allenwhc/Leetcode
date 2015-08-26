import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution {
	public static int[] twoSum(int[] nums, int target){
		int[] index=new int[2];
		if(nums.length<=2) return index;
		Map<Integer , Integer> mp=new HashMap<Integer,Integer>();
		int n=nums.length;
		for(int i=0; i<n; i++)
			mp.put(nums[i], i);
		for(int i=0; i<n; i++){
			if(mp.containsKey(target-nums[i]) && mp.get(target-nums[i])!=i){
				if(i<mp.get(target-nums[i])){
					index[0]=i+1;
					index[1]=mp.get(target-nums[i])+1;
					break;
				}
				else{
					index[0]=mp.get(target-nums[i])+1;
					index[1]=i+1;
					break;
				}
			}
		}
		return index;
	}
	public static void main(String args[]){
		int[] nums={3,2,4};
		int target=6;
		System.out.println("The array is:"+Arrays.toString(nums));
		System.out.println("The target sum is: "+target);
		System.out.println("The indices of the elements are: "+Arrays.toString(twoSum(nums, target)));
	}
}
