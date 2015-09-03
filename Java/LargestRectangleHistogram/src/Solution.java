import java.util.Arrays;
import java.util.Stack;

public class Solution {
	public static int largestRectangleArea(int[] height){
		int n=height.length;
		if(n==0) return 0;
		Stack<Integer> stack=new Stack<>();
		int i=0;
		int maxArea=Integer.MIN_VALUE;
		while(i<n){
			if(stack.isEmpty() || height[stack.peek()]<=height[i]){
				stack.push(i);
				i++;
				continue;
			}
			int j=stack.pop();
			int width=stack.isEmpty()?i:i-stack.peek()-1;
			maxArea=Math.max(maxArea, width*height[j]);
		}
		
		while(!stack.isEmpty()){
			int j=stack.pop();
			int width=stack.isEmpty()?i:i-stack.peek()-1;
			maxArea=Math.max(maxArea, width*height[j]);
		}
		return maxArea;
	}
	
	public static void main(String[] args){
		int[] height={2,1,5,6,2,3};
		System.out.println("The heights of histogram is: "+Arrays.toString(height));
		System.out.println("The largest rectangle area is: "+largestRectangleArea(height));
	}
}