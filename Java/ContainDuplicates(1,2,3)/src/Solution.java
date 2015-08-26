import java.util.HashMap;
import java.util.Map;
import java.util.TreeSet;

public class Solution {
	//Contains Duplicate I
	public static boolean containsDuplicates(int[] nums){
		int n=nums.length;
		if(n<=1) return false;
		Map<Integer, Integer> map=new HashMap<Integer,Integer>();
		for(int i=0; i<n; i++){
			if(map.containsKey(nums[i])) return true;
			else map.put(nums[i], 0);
		}
		return false;
	}
	
	//Contains Duplicate II
	public static boolean containsNearbyDuplicate(int[] nums, int k){
		int n=nums.length;
		if(n<=1) return false;
		Map<Integer, Integer> map=new HashMap<Integer,Integer>();
		for(int i=0; i<n; i++){
			if(map.containsKey(nums[i]) && Math.abs(map.get(nums[i])-i)<=k)
				return true;
			else map.put(nums[i], i);
		}
		return false;
	}
	
	//Contains Duplicate III
	public static boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t){
		int n=nums.length;
		if(n<=1 || k<1 || t<0) return false;
		TreeSet set=new TreeSet<>();
		for(int i=0; i<n; i++){
			Integer floor=nums[i]-t;
			Integer ceiling=nums[i]+t+1;
			if((long)nums[i]-(long)t < Integer.MIN_VALUE) floor=Integer.MIN_VALUE;
			if((long)nums[i]+(long)t+1 > Integer.MAX_VALUE) ceiling=Integer.MAX_VALUE;
			if(t>=0 && set.subSet(floor, ceiling).size()!=0) return true;
			set.add(nums[i]);
			if(i>=k) set.remove(nums[i-k]);
		}
		return false;
	}
	
	//Main 
	public static void main(String[] args){ 
		int[] nums={8, 1, 3, 5, 7, 1, 4, 6};
		//int[] nums={2, 2};
		int k=1;
		int t=1;
		boolean isContain=containsDuplicates(nums);
		boolean isContainNearby=containsNearbyDuplicate(nums, k);
		boolean isContainAlmostNearby=containsNearbyAlmostDuplicate(nums, k, t);
		System.out.print("The array is: ");
		for(int i=0; i<nums.length; i++)
			System.out.print(nums[i]+" ");
		System.out.print("\n"+"The array ");
		if(isContain) System.out.print ("contains duplicates, ");
		else System.out.print("does not contain duplicates, ");
		if(isContainNearby) System.out.print ("contains nearby duplicates (k="+k+"), ");
		else System.out.print("does not contain nearby duplicates (k="+k+"), ");
		if(isContainNearby) System.out.print ("and contains nearby almost duplicates (k="+k+", t="+t+").");
		else System.out.print("and does not contain nearby duplicates (k="+k+", t="+t+").");
	}
}
