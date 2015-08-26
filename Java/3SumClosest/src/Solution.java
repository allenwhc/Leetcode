import java.util.Arrays;

public class Solution {
	public static int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n=nums.length;
        if(n==0) return 0;
        int num1=0,num2=0,num3=0;
        int closest=Integer.MAX_VALUE;
        for(int i=0; i<n-2; i++){
        	int j=i+1;
        	int k=n-1;
        	while(j<k){
        		int sum=nums[i]+nums[j]+nums[k];
        		int diff=Math.abs(sum-target);	//Calculate the difference
        		if(diff==0) return target;
        		else{
        			if(diff<closest){
        				num1=i;
        				num2=j;
        				num3=k;
        				closest=diff;
        			}
        			if(sum>target) k--;
        			else j++;
        		}
        	}
        }
        return nums[num1]+nums[num2]+nums[num3];
    }
	
	public static void main(String[] args){
		int[] nums={-1,2,1,-4};
		int target=1;
		System.out.println("The array is: "+Arrays.toString(nums));
		System.out.println("The closest three sum to "+target+" is: "+threeSumClosest(nums, target));
	}
}
