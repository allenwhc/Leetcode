import java.util.Arrays;
public class Solution {
	//House Robber I, all houses on a straight street
	public static int rob1(int[] nums){
		int n=nums.length;
		if(n<=0) return 0;
		else if(n==1) return nums[0];
		else if(n==2) return Math.max(nums[0], nums[1]);
		else{
			int[] money=new int[n];
			money[0]=nums[0];
			money[1]=Math.max(nums[0], nums[1]);
			for(int i=2; i<n; i++){
				money[i]=Math.max(money[i-1], nums[i]+money[i-2]);
			}
			return money[n-1];
		}
	}
	
	//House Robber II, all houses on a circular street
	public static int rob2(int[] nums) {
		int n=nums.length;
		if(n<=0) return 0;
		else if(n==1) return nums[0];
		else if(n==2) return Math.max(nums[0], nums[1]);
		else{
			//If robs the first house
			int[] money1=new int[n];
			money1[0]=0;
			money1[1]=nums[0];
			for(int i=2; i<n; i++){
				money1[i]=Math.max(money1[i-1], nums[i-1]+money1[i-2]);
			}
			
			//If robs the last house
			int[] money2=new int[n];
			money2[0]=0;
			money2[1]=nums[1];
			for(int i=2; i<n; i++){
				money2[i]=Math.max(money2[i-1], nums[i]+money2[i-2]);
			}
			
			return Math.max(money1[n-1], money2[n-1]);
		}
	}
	
	//Main
	public static void main(String[] args){
		int[] nums={4, 2, 5, 1, 7, 10, 4, 1, 3, 7};
		System.out.println("The property distribution on the street is: "+Arrays.toString(nums));
		System.out.println("If the street is straight, then the maximum amount of money the robber can rob is: "+rob1(nums));
		System.out.println("If the street is circular, then the maximum amount of money the robber can rob is: "+rob2(nums));
	}
}


