import java.util.ArrayList;
import java.lang.*;
import java.util.List;
import java.util.Vector;;
public class NQueens {
	//isValid for N Queens I
	public static boolean isValid1(int row, int col, int[] position){
		for(int i=0; i<row; i++){
			if(col==position[i] || Math.abs(row-i)==Math.abs(col-position[i]))
				return false;
		}
		return true;
	}
	
	//isValid for N Queens II
	public static boolean isValid2(int row, int col, int[] position){
		for(int i=0; i<row; i++){
			if(col==position[i] || Math.abs(row-i)==Math.abs(col-position[i]))
				return false;
		}
		return true;
	}

	public static void solve(int row, int n, int[] position, List<List<String>> allSols){
		if(row==n){
			List<String> item=new ArrayList<String>(n);
			String str="";
			String r="";
			for(int i=0;i<n;i++) str=str+".";
			for(int i=0;i<n;i++) item.add(i, str);
			for(int i=0; i<n; i++){
				if(position[i]==0){
					r = 'Q'+str.substring(position[i],n-1);
				}
				else r=str.substring(0,position[i])+'Q'+str.substring(position[i],n-1);
				item.remove(i);
				item.add(i, r);
			}
			allSols.add(item);
			return;
		}
		else{
			for(int col=0; col<n; col++){
				if(isValid1(row, col, position)){
					position[row]=col;
					solve(row+1, n, position, allSols);
					position[row]=-1;
				}
			}
		}
	}
	
	public static void solveTotalSolutions(int row, int n, int count, int[] position){
		if(row==n){
			count++;
			return;
		}
		else{
			for(int col=0; col<n; col++){
				if(isValid2(row, col, position)){
					position[row]=col;
					solveTotalSolutions(row+1, n, count, position);
					position[row]=-1;
				}
			}
		}
	}
	
	//N Queens I
	public static List<List<String>> solveNQueens(int n){
		List<List<String>> allSols=new ArrayList<List<String>>();
		if(n==0 || n==2 || n==3) return allSols;
		int[] position=new int[n];
		for(int i=0;i<n;i++) position[i]=-1;
		solve(0, n, position, allSols);
		return allSols;
 	}
	
	//N Queens II
	public static int totalNQueens(int n){
		if(n==0 || n==2 || n==3) return 0;
		int count=0;
		int[]position=new int[n];
		for(int i=0; i<n; i++) position[i]=-1;
		solveTotalSolutions(0, n, count, position);
		return count;
	}
	
	//Main method
	public static void main(String[] args) {
		int n=5;
		List<List<String>> allSols=solveNQueens(n);
		int count=totalNQueens(n);
		System.out.println("The total number of solutions for a "+n+"-queen problem is: "+count);
		System.out.println("The solutions for a "+n+"-queen problem are:");
		for(List<String> ls:allSols){
			System.out.println(ls);
		}
	}
}
