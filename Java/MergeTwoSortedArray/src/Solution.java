import java.util.Arrays;

public class Solution {
	public static void merge(int[] nums1, int m, int[] nums2, int n){
		int i=m-1, j=nums1.length-1;
		for(; i>=0; i--){
			nums1[j]=nums1[i];
			j--;
		}
		int k=0;
		i=0;
		j++;
		while(k<(m+n)){
			if((i==n) || j<(m+n) && nums1[j]<=nums2[i]){
				nums1[k]=nums1[j];
				j++;
				k++;
			}
			else{
				nums1[k]=nums2[i];
				i++;
				k++;
			}
		}
	}
	
	public static void main(String[] args) {
		int[] nums1={1,3,6,8,10,0,0,0};
		int m=5;
		int[] nums2={2,5,9};
		int n=3;
		merge(nums1, m, nums2, n);
		System.out.println("The merged sorted array is: "+Arrays.toString(nums1));
	}
}