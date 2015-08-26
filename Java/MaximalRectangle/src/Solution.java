import java.util.Arrays;

import javax.management.loading.MLet;

public class Solution {
	public static int maximalRectangle(char[][] matrix) {
		int m=matrix.length;
		if(m==0) return 0;
		int n=matrix[0].length;
		if(n==0) return 0;
		
		int[][] rectangle=new int[m][n];
		for(int i=0; i<m; i++){
			if(matrix[i][0]=='1')
				rectangle[i][0]=1;
		}
		
		for(int i=0; i<m; i++){
			for(int j=1; j<n; j++)
				if(matrix[i][j]=='1')
					rectangle[i][j]=rectangle[i][j-1]+1;
		}
		
		int maxArea=0;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(rectangle[i][j]!=0){
					int k=i-1;
					int temp=rectangle[i][j];
					int minLen=rectangle[i][j];
					while(k>=0){
						if(matrix[k][j]==0)
							break;
						else{
							minLen=Math.min(minLen, rectangle[k][j]);
							temp=Math.max(temp, minLen*(i-k+1));
							k--;
						}
					}
					maxArea=Math.max(maxArea, temp);
				}
			}
		}
        return maxArea;
    }
	
	public static void main(String[] args) {
		char[][] matrix={{'0','1','1','1','0'},{'0','0','1','1','0'},{'1','0','1','1','0'},{'1','1','0','0','1'},{'1','1','0','0','0'}};
		System.out.println("The matrix is: ");
		for(int i=0; i<matrix.length; i++)
			System.out.println(Arrays.toString(matrix[i]));
		System.out.println("The maximal rectangle is: "+maximalRectangle(matrix));
	}
}
