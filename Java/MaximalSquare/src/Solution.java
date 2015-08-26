
public class Solution {
	public static int maximalSquare(char[][] matrix) {
		int row=matrix.length;
		if(row==0) return 0;
		int col=matrix[0].length;
		if(col==0) return 0;
		
		int[][] width=new int[row][col];
		int maxWidth=0;
		
		//Initialize the first row and column
		for(int i=0; i<row; i++)
			width[i][0]=matrix[i][0]-'0';
		for(int j=0; j<col; j++)
			width[0][j]=matrix[0][j]-'0';
		
		//Compute the width of square
		for(int i=1; i<row; i++){
			for(int j=1; j<col; j++){
				if(matrix[i][j]=='1'){
					int min1=Math.min(width[i][j-1], width[i-1][j]);
					width[i][j]=Math.min(min1, width[i-1][j-1])+1;
				}
			}
		}
		
		//Find the maximum width
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				maxWidth=Math.max(maxWidth, width[i][j]);
			}
		}
		return maxWidth*maxWidth;
    }
	
	public static void main(String[] args){
		char[][] matrix = {
				{ '0', '1', '0', '0', '1' },
				{ '1', '1', '1', '1', '0' },
				{ '0', '1', '1', '1', '0' },
				{ '1', '1', '1', '1', '0' },
				{ '1', '0', '0', '1', '1' },
				{ '0', '1', '1', '1', '0' } };
		System.out.println("The area of the largest square is: "+maximalSquare(matrix));
	}
}
