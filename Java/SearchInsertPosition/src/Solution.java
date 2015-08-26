import java.util.Arrays;
import java.util.HashMap;

public class Solution {
	public static int searchInsert(int[] nums, int target) {
		int n=nums.length;
		if(n==0) return 0;
		HashMap<Integer, Integer> hmap=new HashMap<>();
		for(int i=0; i<n; i++)
			hmap.put(nums[i], i);
		if(hmap.containsKey(target)) return hmap.get(target);
		if(target<nums[0]) return 0;
		int i=1;
		while(i<n){
			if(target<nums[i]) break;
			i++;
		}
        return i;
    }
	
	public static void main(String[] args) {
		int[] nums={1,3,5,6};
		int[] targets={5,2,7,0};
		for(int i:targets){
			System.out.println("The inserting position of "+i+" in "+Arrays.toString(nums)+" is: "+searchInsert(nums, i));
		}
	}
}
