import java.util.Arrays;

public class Solution {
	public static int canCompleteCircuit(int[] gas, int[] cost){
		int n=gas.length;
		int[] tank=new int[n];
		
		//Initialize tank
		for(int i=0; i<n; i++)
			tank[i]=gas[i]-cost[i];
		
		int leftGas=0, totalGas=0, startStation=0;
		for(int i=0; i<n; i++){
			leftGas+=tank[i];
			totalGas+=tank[i];
			if(totalGas<0){
				startStation++;
				totalGas=0;
			}
		}
		if(leftGas>=0) return startStation;
		else return -1;
	}
	
	public static void main(String[] args){
		int[] gas={3,4,6,5,4};
		int[] cost={5,2,7,3,5};
		System.out.println("The mount of gas:"+Arrays.toString(gas));
		System.out.println("The mount of gas cost:"+Arrays.toString(cost));
		System.out.println("The starting gas station is the "+canCompleteCircuit(gas, cost)+"th");
	}
}
