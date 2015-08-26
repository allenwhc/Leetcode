import java.util.Arrays;

public class Solution {
	public static int maxArea(int[] height) {
        int n=height.length;
        if(n==0) return 0;
        int left=0;
        int right=n-1;
        int volume=0;
        while(left<right){
        	volume=Math.max(volume, Math.min(height[left], height[right])*(right-left));
        	if(height[left]<height[right])
        		left++;
        	else right--;
        }
        return volume;
    }
	public static void main(String[] args){
		int[] height={3,2,4,1,3,4,2,1};
		System.out.println("The height of container is: "+Arrays.toString(height));
		System.out.println("The maximum water contained is: "+maxArea(height));
	}
}
