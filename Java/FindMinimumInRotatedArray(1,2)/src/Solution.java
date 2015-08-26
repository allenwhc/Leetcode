import java.util.Arrays;
import java.util.Random;

public class Solution {
	public static int findMin(int[] nums){
		int n=nums.length;
		if(n<=0) return 0;
		int start=0,end=n-1;
		while(start<end){
			int middle=(start+end)/2;
			if(nums[start]<nums[end]) return nums[start];
			if(nums[start] < nums[middle]) start=middle;
			else if(nums[start] > nums[middle]) end=middle;
			else start++;
		}
		return Math.min(nums[start], nums[end]);
	}
	public static void main(String[] args){
		int[] nums1={1,2,3,4,5,6,7};
		int[] nums2={1,1,1,1,3};
		Random rand=new Random();
		int pivot1=rand.nextInt(nums1.length);
		int pivot2=rand.nextInt(nums2.length);
		int[] n1=new int[nums1.length];
		int[] n2=new int[nums2.length];
		if(pivot1 != 0){
			for(int i=0; i<nums1.length-pivot1; i++)
				n1[i]=nums1[i+pivot1];
			for(int i=nums1.length-pivot1; i<nums1.length; i++)
				n1[i]=nums1[i-nums1.length+pivot1];
		}
		else n1=nums1;
		if(pivot2 != 0){
			for(int i=0; i<nums2.length-pivot2; i++)
				n2[i]=nums2[i+pivot2];
			for(int i=nums2.length-pivot2; i<nums2.length; i++)
				n2[i]=nums2[i-nums2.length+pivot2];
		}
		else n2=nums2;
		System.out.print("The input array with no duplicate elements is:");
		System.out.println(Arrays.toString(n1));
		int m1=findMin(n1);
		System.out.println("The minimum element in the above array is: "+m1);
		System.out.print("The input array with duplicate elements is:");
		System.out.println(Arrays.toString(n2));
		int m2=findMin(n2);
		System.out.println("The minimum element in the above array is: "+m2);
	}
}
