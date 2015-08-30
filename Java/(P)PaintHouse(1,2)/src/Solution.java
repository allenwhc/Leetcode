import java.util.HashMap;

public class Solution {
	//Paint House I
	public static int minCost(int[][] costs){
		int num=costs.length;
		if(num==0) return 0;
		int[][] total_costs=new int[2][3];
		
		int result=Integer.MAX_VALUE;
		
		for(int j=0; j<3; j++)
			total_costs[0][j]=costs[0][j];
		
		for(int i=1; i<num; i++){
			total_costs[1][0]=costs[i][0]+Math.min(total_costs[0][1], total_costs[0][2]);	//Cost for choosing red to paint current house
			total_costs[1][1]=costs[i][1]+Math.min(total_costs[0][0], total_costs[0][2]);	//Cost for choosing green to paint current house
			total_costs[1][2]=costs[i][2]+Math.min(total_costs[0][0], total_costs[0][1]);	//Cost for choosing blue to paint current house
			
			//Update the current costs
			total_costs[0][0]=total_costs[1][0];
			total_costs[0][1]=total_costs[1][1];
			total_costs[0][2]=total_costs[1][2];
		}
		
		for(int j=0; j<3; j++)
			result=Math.min(result, total_costs[0][j]);
		return result;
	}
	
	//Paint House II
	public static int minCostII(int[][] costs) {
        int m=costs.length;
        if(m==0) return 0;
        int n=costs[0].length;
        if(n==0) return 0;
        
        int[] total_costs=new int[n];
        
        int min1=0, min2=0;
        for(int i=0; i<m; i++){
        	int prev_min1=min1;
        	int prev_min2=min2;		//Save previous minimum and second to minimum
        	min1=Integer.MAX_VALUE;
        	min2=Integer.MAX_VALUE;
        	for(int j=0; j<n; j++){
        		total_costs[j]=(total_costs[j]==prev_min1?prev_min2:prev_min1)+costs[i][j];
        		if(min1<total_costs[j]){
        			min2=Math.min(min2, total_costs[j]);
        		}
        		else{
        			min2=min1;
        			min1=total_costs[j];
        		}
        	}
        }
        return min1;
    }
	public static void main(String[] args){
		System.out.println("Paint House I:");
		int[][] costs={{3,1,2},{4,1,5},{4,1,3},{4,2,1},{1,3,4},{3,1,5}};
		System.out.println("The costs of painting different houses:");
		for(int i=0; i<costs.length; i++){
			System.out.print("House "+ (i+1)+": ");
			System.out.print("R-"+costs[i][0]+", ");
			System.out.print("G-"+costs[i][1]+", ");
			System.out.print("B-"+costs[i][2]+";");
			System.out.println();
		}
		System.out.println("The minimum cost for painting all houses is: "+minCost(costs));
		System.out.println();
		System.out.println("Paint House II:");
		int[][] costs2={{3,1,2,4},{4,1,5,3},{4,1,3,2},{4,2,1,5},{1,3,4,2},{3,1,5,4}};
		for(int i=0; i<costs2.length; i++){
			System.out.print("House "+ (i+1)+": ");
			for(int j=0; j<costs2[i].length; j++){
				System.out.print("color "+j+"-"+costs2[i][j]+", ");
			}
			System.out.println();
		}
		System.out.println("The minimum cost for painting all houses is: "+minCostII(costs2));
	}
}
