
public class Solution {
	//Word Search I
	public static boolean exist(char[][] board, String word) {
        int m=board.length;
        if(m==0) return false;
        int n=board[0].length;
        if(n==0) return false;
        boolean canFind=false;
        for(int i=0; i<m; i++)
        	for(int j=0; j<n; j++)
        		if(dfs(board, word, i, j, 0))
        			canFind=true;
        return canFind;
    }
	
	private static boolean dfs(char[][] board, String word, int i, int j, int charIndex){
		int m=board.length;
		int n=board[0].length;
		if(i<0 || j<0 || i>=m || j>=n) return false;
		if(board[i][j]==word.charAt(charIndex)){
			char c=board[i][j];
			board[i][j]='#';
			if(charIndex==word.length()-1) return true;
			else if(dfs(board, word, i+1, j, charIndex+1)
					|| dfs(board, word, i-1, j, charIndex+1)
					|| dfs(board, word, i, j+1, charIndex+1)
					|| dfs(board, word, i, j-1, charIndex+1))
				return true;
			board[i][j]=c;
		}
		return false;
	}
	
	public static void main(String[] args) {
		char[][] board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
		String[] words={"ABCCED","SEE","ABCB"};
		boolean[] canFind=new boolean[words.length];
		for(int i=0; i<words.length; i++){
			canFind[i]=exist(board, words[i]);
			if(canFind[i])
				System.out.println(words[i]+" can be found in the board");
			else
				System.out.println(words[i]+" cannot be found in the board");
		}
	}
}
