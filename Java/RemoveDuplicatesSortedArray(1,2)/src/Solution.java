import java.util.Arrays;
import java.util.HashMap;

public class Solution {
	//Remove duplicates I, return array size without duplicates and modify the array in-place
	public static int removeDuplicates(int[] nums) {
        int n=nums.length;
        if(n==0) return 0;
        int j=0;
        int i=1;
        for(; i<n; i++){
    	    if(nums[i]==nums[j]) continue;
    	    j++;
    	    nums[j]=nums[i];
        }
      //  System.out.println(Arrays.toString(nums));
        return j+1;
    }
	
	//Remove duplicates II, each element is allowed to appear at most twice
	public static int removeDuplicates2(int[] nums) {
        int n=nums.length;
        if(n==0) return 0;
        int i=1;
        int j=0;
        int occur=1;
        for(; i<n; i++){
        	if(nums[i]==nums[j]){
        		if(occur==2) continue;
        		occur++;
        	}
        	else occur=1;
        	j++;
        	nums[j]=nums[i];
        }
        return j+1;
    }
	
	public static void main(String[] args){
		int[] nums={1,1,2,2,3,4,5,5,6,6,6,8};
		int[] nums2={1,1};//,1,2,2,3};
		System.out.println("The sorted array with duplicates is: "+Arrays.toString(nums));
		System.out.println("Length without duplicates is: "+removeDuplicates(nums));
		System.out.println("The sorted array with duplicates is: "+Arrays.toString(nums2));
		System.out.println("Length without duplicates (allowed twice) is: "+removeDuplicates2(nums2));
	}
}
