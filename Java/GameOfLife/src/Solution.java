import java.util.Arrays;


public class Solution {
	public static void gameOfLife(int[][] board){
		int m=board.length;
		if(m==0) return;
		int n=board[0].length;
		if(n==0) return;
		
		boolean[][] states=isLive(board);
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(states[i][j])
					board[i][j]=1;
				else
					board[i][j]=0;
			}
		}
			
	}
	
	private static boolean[][] isLive(int[][] board){
		int m=board.length;
		int n=board[0].length;
		boolean[][] states=new boolean[m][n];
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				int countLive=0;
				if(i>0 && j>0 && board[i-1][j-1]==1) countLive++;
				if(i>0 && board[i-1][j]==1) countLive++;
				if(i>0 && j<n-1 && board[i-1][j+1]==1) countLive++;
				if(j>0 && board[i][j-1]==1) countLive++;
				if(j<n-1 && board[i][j+1]==1) countLive++;
				if(i<m-1 && j>0 && board[i+1][j-1]==1) countLive++;
				if(i<m-1 && board[i+1][j]==1) countLive++;
				if(i<m-1 && j<n-1 && board[i+1][j+1]==1) countLive++;
				
				if(board[i][j]==1){
					if(countLive<2) states[i][j]=false;	//under-population
					else if(countLive==2 || countLive==3) states[i][j]=true;	//live
					else states[i][j]=false;	//over-population
				}	
				else{
					if(countLive==3) states[i][j]=true;	//reproduction
					else states[i][j]=false;
				}
			}
		}
		return states;
		
	}
	
	public static void main(String[] args) {
//		int[][] board={
//				{0,0,0,0,0,0},
//				{0,1,1,0,0,0},
//				{0,1,0,0,0,0},
//				{0,0,0,0,1,0},
//				{0,0,0,1,1,0},
//				{0,0,0,0,0,0}
//		};
		
		int[][] board={{1,1},{1,0}};
		System.out.println("The initial state of 'Beacon' is: ");
		for(int[] cc:board)
			System.out.println(Arrays.toString(cc));
		gameOfLife(board);
		System.out.println("The next state of 'Beacon' is: ");
		for(int[] cc:board)
			System.out.println(Arrays.toString(cc));
	}
}
