import java.util.Arrays;

public class Solution {
    public static int numSquares(int n) {
    	if(n<=0) return 0;
    	int[] count=new int[n+1];
    	int base=(int)Math.sqrt(n);
    	for(int i=0; i<=n; i++)
    		count[i]=i;
    	
    	for(int i=2; i<=base; i++){
    		for(int j=0; j<=n; j++){
    			int square=i*i;
    			if(square<=j)
    				count[j]=Math.min(count[j], count[j-square]+1);
    		}
    		//System.out.println(Arrays.toString(count));
    	}
        return count[n];
    }
    
    public static void main(String[] args) {
		int[] n={12,13,19,23,27,35};
		for(int i:n)
			System.out.println("The number of squares included in "+i+" is: "+numSquares(i));
	}
}