
public class Solution {
	public static int numIslands(char[][] grid) {
        int m=grid.length;
        if(m==0) return 0;
        int n=grid[0].length;
        if(n==0) return 0;
        
        int num=0;
        for(int i=0; i<m; i++){
        	for(int j=0; j<n; j++){
        		if(grid[i][j]!='1') continue;
        		num++;
        		bfs(grid, i, j);
        	}
        }
        return num;
    }
	
	private static void bfs(char[][] grid, int i, int j){
		int m=grid.length;
		int n=grid[0].length;
		if(i<0 || j<0 || i>=m || j>=n) return;
		if(grid[i][j]=='1'){
			grid[i][j]='*';
			bfs(grid, i+1, j);
			bfs(grid, i-1, j);
			bfs(grid, i, j+1);
			bfs(grid, i, j-1);
		}
	}
	
	public static void main(String[] args) {
		char[][] grid={{'1','1','0','0','0'},
						{'1','1','0','0','0'},
						{'0','0','1','0','0'},
						{'0','0','0','1','1'}};
		System.out.println("There are "+numIslands(grid)+" islands in the grid");
	}
}
