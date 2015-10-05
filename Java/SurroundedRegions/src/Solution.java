import java.util.Arrays;

public class Solution {
	public static void solve(char[][] board) {
        int m=board.length;
        if(m==0) return;
        int n=board[0].length;
        if(n==0) return;
        
        for(int i=1; i<m; i++)
        	bfs(board, i, n-1);
        for(int i=1; i<m-1; i++)
        	bfs(board, i, 0);
        for(int j=0; j<n; j++)
        	bfs(board, 0, j);
        for(int j=0; j<n-1; j++)
        	bfs(board, m-1, j);
        for(int i=0; i<m; i++)
        	for(int j=0; j<n; j++){
        		board[i][j]=(board[i][j]=='M')?'O':'X';
        	}
    }
	
	private static void bfs(char[][] board, int i, int j){
		int m=board.length;
		int n=board[0].length;
		if(board[i][j]=='X' || board[i][j]=='M') return;
		board[i][j]='M';
		if(i<m-1) bfs(board, i+1, j);
		if(i>1) bfs(board, i-1, j);
		if(j<n-1) bfs(board, i, j+1);
		if(j>1) bfs(board, i, j-1);
	}
	
	public static void main(String[] args) {
		char[][] board={{'O','X','O'},
				  {'X','O','X'},
				  {'O','X','O'}};
		System.out.println("The original board is: ");
		for(char[] cc:board)
			System.out.println(Arrays.toString(cc));
		solve(board);
		System.out.println("The revised board is: ");
		for(char[] cc:board)
			System.out.println(Arrays.toString(cc));
	}
}