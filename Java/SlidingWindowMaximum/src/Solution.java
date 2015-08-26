import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class Solution {
	public static int[] maxSlidingWindow(int[] nums, int k){
		Deque<Integer> dq=new LinkedList<Integer>();
		int n=nums.length;
		if(n==0 || n<k) return new int[0];
		List<Integer> save=new ArrayList<Integer>();
		
		//Initialize the dq
		for(int i=0; i<k; i++){
			while(!dq.isEmpty() && nums[i]>=nums[dq.getLast()])
				dq.pollLast();
			dq.addLast(i);
		}
		
		//Slide the window
		for(int i=k; i<n; i++){
			save.add(nums[dq.getFirst()]);
			while(!dq.isEmpty() && dq.getFirst()<=i-k)
				dq.pollFirst();
			while(!dq.isEmpty() && nums[i]>=nums[dq.getLast()])
				dq.pollLast();
			dq.addLast(i);
		}
		save.add(nums[dq.getFirst()]);
		
		int[] res=new int[save.size()];
		for(int i=0; i<save.size(); i++)
			res[i]=save.get(i);
		return res;
	}
	
	public static void main(String[] args) {
		int[] nums={1,3,-1,-3,5,3,6,7};
		int k=3;
		System.out.println("The maximums in a "+k+"-element long windows are: "+Arrays.toString(maxSlidingWindow(nums, k)));
		
	}
	
}
