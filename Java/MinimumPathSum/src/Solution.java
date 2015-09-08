import java.util.Arrays;

public class Solution {
	public static int minPathSum(int[][] grid) {
        int m=grid.length;
        if(m==0) return 0;
        int n=grid[0].length;
        if(n==0) return 0;
        int[][] pathSum=new int[m][n];
        pathSum[0][0]=grid[0][0];
        for(int i=1; i<m; i++)
        	pathSum[i][0]=pathSum[i-1][0]+grid[i][0];
        for(int j=1; j<n; j++)
        	pathSum[0][j]=pathSum[0][j-1]+grid[0][j];
        for(int i=1; i<m; i++){
        	for(int j=1; j<n; j++)
        		pathSum[i][j]=Math.min(pathSum[i][j-1], pathSum[i-1][j])+grid[i][j];
        }
        return pathSum[m-1][n-1];
    }
	
	public static void main(String[] args) {
		int[][] grid = { {3,4,10,2},
				 		{1,7,2,4},
				 		{5,4,2,3}};
		System.out.println("The grid is: ");
		for(int[] row:grid)
			System.out.println(Arrays.toString(row));
		System.out.println("The minimum path sum is: "+minPathSum(grid));
	}
}
