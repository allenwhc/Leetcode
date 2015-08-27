
public class Solution {
	public static int countDigitOne(int n){
		if(n<=0) return 0;
		if(n<10) return 1;
		int count=0;
		for(long i=1; i<=n; i*=10){
			long q=n/i;
			long r=n%i;
			count+=(q+8)/10*i+(q%10==1?r+1:0);
		}
		return count;
	} 
	
	public static void main(String[] args){
		int n=13;
		System.out.println(countDigitOne(n));
	}
	
}
