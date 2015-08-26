import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	//Spiral Matrix I, return all elements of the matrix in spiral order
	public static List<Integer> spiralOrder(int[][] matrix){
		List<Integer> spiralOutput=new ArrayList<Integer>();
		int m=matrix.length;
		if(m==0) return spiralOutput;
		int n=matrix[0].length;
		int top=0;
		int down=m-1;
		int left=0;
		int right=n-1;
		
		while(true){
			//first row
			for(int i=left; i<=right; i++)
				spiralOutput.add(matrix[top][i]);
			top++;
			if(top>down || left>right) break;
			
			//last column
			for(int i=top; i<=down; i++)
				spiralOutput.add(matrix[i][right]);
			right--;
			if(top>down || left>right) break;
			
			//last row
			for(int i=right; i>=left; i--)
				spiralOutput.add(matrix[down][i]);
			down--;
			if(top>down || left>right) break;
			
			//first column
			for(int i=down; i>=top; i--)
				spiralOutput.add(matrix[i][left]);
			left++;
			if(top>down || left>right) break;
		}
		return spiralOutput;
	}
	
	//Spiral matrix II, return a n*n spiral matrix
	public static int[][] generateMatrix(int n){
		int[][] spiralMatrix=new int[n][n];
		if(n<=0) return spiralMatrix;
		int top=0;
		int down=n-1;
		int left=0;
		int right=n-1;
		int lastFirstRow=1, lastLastColumn=1, lastLastRow=1, lastFirtColumn=1;
		
		while(true){
			//First Row
			for(int i=left; i<=right; i++)
				spiralMatrix[top][i]=lastFirtColumn+i-left;
			lastFirstRow=spiralMatrix[top][right]+1;
			top++;
			if(top>down || left>right) break;
			
			//Last column
			for(int i=top; i<=down; i++)
				spiralMatrix[i][right]=lastFirstRow+i-top;
			lastLastColumn=spiralMatrix[down][right]+1;
			right--;
			if(top>down || left>right) break;
			
			//Last row
			for(int i=right; i>=left; i--)
				spiralMatrix[down][i]=lastLastColumn-i+right;
			lastLastRow=spiralMatrix[down][left]+1;
			down--;
			if(top>down || left>right) break;
			
			//First column
			for(int i=down; i>=top; i--)
				spiralMatrix[i][left]=lastLastRow-i+down;
			lastFirtColumn=spiralMatrix[top][left]+1;
			left++;
			if(top>down || left>right) break;
		}
		return spiralMatrix;
	}
	
	//Main
	public static void main(String[] args) {
		int x=5;
		int[][] matrix=new int[x][x];
		int val=0;
		for(int i=0; i<x; i++){
			for(int j=0; j<x; j++){
				matrix[i][j]=val+j+1;
			}
			val=matrix[i][x-1];
		}
		System.out.println("The original matrix is:");
		for(int i=0; i<x; i++)
			System.out.println(Arrays.toString(matrix[i]));
		System.out.println("The spiral output is:"+Arrays.deepToString(spiralOrder(matrix).toArray()));
		System.out.println("The spiral matrix is");
		for(int i=0; i<x; i++)
			System.out.println(Arrays.toString(generateMatrix(x)[i]));
	}
}
