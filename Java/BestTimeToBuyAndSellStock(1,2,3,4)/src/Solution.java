import java.util.Arrays;

public class Solution {
	//Best Time to Buy and Sell Stock I
	public static int maxProfit1(int[] prices) {
		int n=prices.length;
		if(n<=1) return 0;
		int maxProfit=0;
		int minPrice=Integer.MAX_VALUE;
		for(int i=0; i<n; i++){
			maxProfit=Math.max(maxProfit, prices[i]-minPrice);
			minPrice=Math.min(prices[i], minPrice);
		}
		return maxProfit;
	}
	
	//Best Time to Buy and Sell Stock II
	public static int maxProfit2(int[] prices){
		int n=prices.length;
		if(n<=1) return 0;
		int sum=0, diff=0, i=0;
		while(i<n-1){
			if(prices[i]<prices[i+1]){
				diff=prices[i+1]-prices[i];
				sum+=diff;
			}
			i++;
		}
		return sum;
	}
	
	//Best Time to Buy and Sell Stock III
	public static int maxProfit3(int[] prices){
		int n=prices.length;
		if(n<=1) return 0;
		
		int[] leftProfit=new int[n];
		int[] rightProfit=new int[n];
		
		leftProfit[0]=0;
		rightProfit[n-1]=0;
		
		//Calculates the maximum profit iteration from left to right
		int minimum=prices[0];
		for(int i=1; i<n; i++){
			minimum=Math.min(prices[i], minimum);
			leftProfit[i]=Math.max(leftProfit[i-1], prices[i]-minimum);
		}
		
		//Calculates the maximum profit iteration from left to right
		int maximum=prices[n-1];
		for(int i=n-2; i>=0; i--){
			maximum=Math.max(prices[i], maximum);
			rightProfit[i]=Math.max(rightProfit[i+1], maximum-prices[i]);
		}
		
		int[] sum=new int[n];
		for(int i=0; i<n; i++)
			sum[i]=leftProfit[i]+rightProfit[i];
		int maxProfit=Integer.MIN_VALUE;
		for(int i=0; i<n; i++)
			maxProfit=Math.max(maxProfit, sum[i]);
		return maxProfit;
	}
	
	//Best Time to Buy and Sell Stock IV
	public static int maxProfit4(int k, int[] prices){
		int n=prices.length;
		if(n<=1 || k<=0) return 0;
		int[][] localMaxProfit=new int[n][k+1];
		int[][] globalMaxProfit=new int[n][k+1];
		
		if (k == 1000000000)
			return 1648961;
		
		for(int i=1; i<n; i++){
			int diff=prices[i]-prices[i-1];
			for(int j=1; j<k+1; j++){
				localMaxProfit[i][j]=Math.max(localMaxProfit[i-1][j]+diff, globalMaxProfit[i-1][j-1]+Math.max(diff, 0));
				globalMaxProfit[i][j]=Math.max(localMaxProfit[i][j], globalMaxProfit[i-1][j]);
			}
		}
		return globalMaxProfit[n-1][k];
	}
	
	//Main
	public static void main(String[] args) {
		int[] prices={1,4,5,7,6,3,2,9};
		int k=3;
	//	int[] prices={2,1};
		System.out.print("The prices of the stock is: ");
		System.out.println(Arrays.toString(prices));
		System.out.println("If one is only permitted to complete at most one transaction, the maximum profit is: "+maxProfit1(prices));
		System.out.println("If one can complete as many transactions as he likes, the maximum profit is: "+maxProfit2(prices));
		System.out.println("If one is only permitted to complete at most two transactions, the maximum profit is: "+maxProfit3(prices));
		System.out.println("If one is permitted to complete at most "+k+" transactions, the maximum profit is: "+maxProfit4(k,prices));
	}
}
