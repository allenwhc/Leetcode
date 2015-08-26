import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	//Palindrome partitioning I
	public static List<List<String>> partition(String s) {
        List<List<String>> allSols=new ArrayList<List<String>>();
        List<String> sol=new ArrayList<String>();
        if(s.length()==0) return allSols;
        dfs(allSols, sol, s, 0);
        return allSols;
    }
	
	public static void dfs(List<List<String>> allSols, List<String> sol, String s, int step){
		if(step==s.length()){
			allSols.add(new ArrayList<String>(sol));
			return;
		}
		
		for(int i=step;i<s.length(); i++){
			if(isPalindrome(s, step, i)){
				sol.add(s.substring(step,i+1));
				dfs(allSols, sol, s, i+1);
				sol.remove(sol.size()-1);
			}
		}
	}
	
	//Palindrome partition
	public static int minCut(String s){
		int n=s.length();
		if(n==0) return 0;
		int[] cut=new int[n];
		boolean[][] isPalin=new boolean[n][n];
		
		for(int i=0; i<n; i++){
			cut[i]=i;
			for(int j=0; j<=i; j++){
				if(s.charAt(i)==s.charAt(j) && (i-j <2 || isPalin[j+1][i-1])){
					isPalin[j][i]=true;
					if(j>0) cut[i]=Math.min(cut[i], cut[j-1]+1);
					else cut[i]=0;
				}
			}
		}
		return cut[n-1];
	}
	
	private static boolean isPalindrome(String s,int start, int end){
		if(start>end) return false;
		while(start<=end){
			if(s.charAt(start)!=s.charAt(end)) return false;
			start++;
			end--;
		}
		return true;
	}
	
	public static void main(String[] args){
		String s="aab";
		System.out.println("The string is: "+s);
		System.out.println("All palindrome partitions are:");
		for(List<String> ss:partition(s))
			System.out.println(Arrays.deepToString(ss.toArray()));
		System.out.println("The minimum cut is: "+minCut(s));
	}
}
