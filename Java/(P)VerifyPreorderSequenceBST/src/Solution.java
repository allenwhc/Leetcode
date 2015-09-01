import java.util.Arrays;
import java.util.Stack;

public class Solution {
	public static boolean verifyPreorder(int[] nums){
		Stack<Integer> stack=new Stack<>();
		int n=nums.length;
		if(n==0) return true;
		int last=-1;
		for(int i=0; i<n; i++){
			if(nums[i]<last) return false;
			while(!stack.isEmpty() && nums[i]>stack.peek())
				last=stack.pop();
			stack.push(nums[i]);
		}
		return true;
	}
	
	public static void main(String[] args){
		int[] nums={15,3,7,1,5,11,9,13,23,19,17,21,27,25,29};
		System.out.print(Arrays.toString(nums));
		if(verifyPreorder(nums))
			System.out.println(" is a preorder sequence of a BST.");
		else
			System.out.println(" is not a preorder sequence of a BST.");
	}
}
