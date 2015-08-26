
public class Solution {
	public static int trailingZeroes(int n){
		if(n<=0) return 0;
		int count=0;
		while(n>0){
			count+=n/5;
			n/=5;
		}
		return count;
	}
	
	public static void main(String[] args){
		int n=5;
		System.out.println("There are "+trailingZeroes(n)+" trailing zeroes in "+n+"!.");
	}
}
