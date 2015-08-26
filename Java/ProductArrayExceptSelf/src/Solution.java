import java.util.Arrays;

public class Solution {
	public static int[] productExceptSelf(int[] nums) {
        int n=nums.length;
        int[] product=new int[n];
        if(n==0) return product;
        product[0]=1;
        for(int i=1; i<n; i++)
        	product[i]=product[i-1]*nums[i-1];
        int rear=1;
        for(int i=n-2; i>=0; i--){
        	rear*=nums[i+1];
        	product[i]*=rear;
        }
        return product;
    }
	
	public static void main(String[] args) {
		int[] nums={9,0,-2};
		System.out.println("The array is: "+Arrays.toString(nums));
		System.out.println("The product array except self is: "+Arrays.toString(productExceptSelf(nums)));
	}
}
