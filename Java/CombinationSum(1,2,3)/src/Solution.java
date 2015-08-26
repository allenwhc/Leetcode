import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
public class Solution {
	//Combination Sum 3
	public static List<List<Integer>> combinationSum3(int k, int n){
		List<List<Integer>> allSol=new ArrayList<List<Integer>>();
		List<Integer> sol=new ArrayList<Integer>();
		if(n==0) return allSol;
		searchCombination(allSol, sol, k, n, 0, 1);
		return allSol;
	}
	
	private static void searchCombination(List<List<Integer>> allSol, List<Integer> sol, int k, int n, int sum, int num){
		if(sum>n || sol.size()>k) return;
		if(sum==n && sol.size()==k) allSol.add(new ArrayList<Integer>(sol));
		else{
			for(int i=num; i<=9; i++){
				sol.add(i);
				searchCombination(allSol, sol, k, n, sum+i, i+1);
				sol.remove(sol.size()-1);
			}
		}
	}
	
	//Main function
	public static void main(String[] args){
		System.out.println("Combination Sum III:");
		int k=3;
		int n=9;
		System.out.println("All possible solutions for "+k+" numbers adding up to "+n+" are:");
		List<List<Integer>> res=combinationSum3(k, n);
		for(List<Integer> ls:res){
			System.out.print(Arrays.deepToString(ls.toArray())+",");
		}
	}
}
