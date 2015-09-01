import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	public static List<List<Integer>> getFactors(int n){
		List<List<Integer>> allFactors=new ArrayList<List<Integer>>();
		if(n<=1) return allFactors;
		List<Integer> factors=new ArrayList<>();
		backTracking(n, 2, factors, allFactors);
		return allFactors;
	}
	
	private static void backTracking(int n, int start, List<Integer> factors, List<List<Integer>> allFactors){
		if(n<=1){
			if(factors.size()>1)
				allFactors.add(new ArrayList<Integer>(factors));
			return;
		}
		
		for(int i=start; i<=n; i++){
			if(n%i==0){
				factors.add(i);
				backTracking(n/i, i, factors, allFactors);
				factors.remove(factors.size()-1);
			}
		}
	}
	
	public static void main(String[] args){
		int n=315;
		System.out.println("All factors of "+n+" are: ");
		for(List<Integer> l:getFactors(n))
			System.out.println(Arrays.deepToString(l.toArray()));
	}
}
