
public class Solution {
	public static int numWays(int n, int k){
		if(n<2 || k==0) return n*k;
		int same=k;
		int diff1=k, diff2=k*(k-1);
		for(int i=2; i<n; i++){
			same=diff2;
			diff2=(k-1)*(diff1+diff2);
			diff1=same;
		}
		return same+diff2;
	}
	
	public static void main(String[] args) {
		int n=5;
		int k=7;
		System.out.println("There are "+numWays(n, k)+" ways to paint "+n+" houses in "+k+" colors.");
	}
}
