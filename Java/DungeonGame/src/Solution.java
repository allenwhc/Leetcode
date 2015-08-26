import java.awt.Dimension;
import java.util.Arrays;

public class Solution {
	public static int calculateMinimumHP(int[][] dungeon) {
		int row=dungeon.length;
		if(row==0) return 0;
		int col=dungeon[0].length;
		if(col==0) return 0;
		
		int[][] hp=new int[row][col];
		
		//Determine the HP before entering the last room
		hp[row-1][col-1]=Math.max(1, 1-dungeon[row-1][col-1]);
		
		int minRight=0;
		int minDown=0;
		
		//Initialize last column
		for(int i=row-2; i>=0; i--)
			hp[i][col-1]=Math.max(1,hp[i+1][col-1]-dungeon[i][col-1]);
		
		//Initialize last row
		for(int j=col-2; j>=0; j--)
			hp[row-1][j]=Math.max(1, hp[row-1][j+1]-dungeon[row-1][j]);
		
		//Calculate the minimum HP backtracking both right path and down path
		for(int i=row-2;i>=0;i--){
			for(int j=col-2; j>=0; j--){
				minRight=Math.max(1, hp[i][j+1]-dungeon[i][j]);
				minDown=Math.max(1, hp[i+1][j]-dungeon[i][j]);
				hp[i][j]=Math.min(minDown, minRight);
			}
		}
        return hp[0][0];
    }
	
	//Main method
	public static void main(String[] args) {
		int[][] dungeon={{-2,-3,3},{-5,-10,1},{10,30,-5}};
		System.out.println("The dungeon is: ");
		for(int i=0; i<dungeon.length; i++)
			System.out.println(Arrays.toString(dungeon[i]));
		System.out.println("The minimum health point is: "+calculateMinimumHP(dungeon));
	}
}
