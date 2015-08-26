import java.util.Arrays;

public class Solution {
	//Unique Paths I, return number of all possible paths (no obstacles)
	public static int uniquePaths(int m, int n){
		int[][] paths=new int[m][n];
		if(m==0||n==0) return 0;
		for(int i=0; i<n; i++)
			paths[0][i]=1;
		for(int i=0; i<m; i++)
			paths[i][0]=1;
		for(int i=1; i<m; i++){
			for(int j=1; j<n; j++)
				paths[i][j]=paths[i-1][j]+paths[i][j-1];
		}
		return paths[m-1][n-1];
	}
	
	//Unique Paths II, return number of all possible paths (with obstacles)
	public static int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid.length==0 || obstacleGrid[0].length==0 || obstacleGrid[0][0]==1) return 0;
        int[][] noPaths=new int[obstacleGrid.length][obstacleGrid[0].length];
        for(int i=0; i<obstacleGrid[0].length; i++){
        	if(obstacleGrid[0][i]==0)
        		noPaths[0][i]=1;
        	else break;
        }
        
        for(int i=0; i<obstacleGrid.length; i++){
        	if(obstacleGrid[i][0]==0)
        		noPaths[i][0]=1;
        	else break;
        }
        
        for(int i=1; i<obstacleGrid.length; i++){
        	for(int j=1; j<obstacleGrid[0].length; j++){
        		if(obstacleGrid[i][j]==1)
        			noPaths[i][j]=0;
        		else
        			noPaths[i][j]=noPaths[i-1][j]+noPaths[i][j-1];
        	}
        }
        return noPaths[obstacleGrid.length-1][obstacleGrid[0].length-1];
    }
	
	//Main
	public static void main(String[] args){
		int m=3;
		int n=7;
		int [][] obstacleGrid={{0,0,0,1,0,0,0},{0,1,0,0,0,0,0},{0,0,0,0,0,1,0}};
		System.out.println("Number of possible paths for a "+m+"*"+n+" grid is: "+uniquePaths(m, n));
		System.out.println("The obstacle grid is: ");
		for(int i=0; i<obstacleGrid.length; i++)
			System.out.println(Arrays.toString(obstacleGrid[i]));
		System.out.println("Number of possible paths for the given grid is: "+uniquePathsWithObstacles(obstacleGrid));
	}
}
