
public class Solution {
	public static int candy(int[] ratings) {
        int n=ratings.length;
        if(n==0) return 0;
        int minCandy=0;
        int[] candies=new int[n];
        //Initialize the # of candies
        for(int i=0; i<n; i++)
        	candies[i]=1;
        
        //Scan from left to right
        for(int i=1; i<n; i++){
        	if(ratings[i]>ratings[i-1])
        		candies[i]=candies[i-1]+1;
        	
        }
        
        for(int i=n-2; i>=0; i--){
        	if(ratings[i]>ratings[i+1])
        		candies[i]=Math.max(candies[i], candies[i+1]+1);
        }
        
        for(int i=0; i<n; i++)
        	minCandy+=candies[i];
        return minCandy;
    }
	
	//Main Method
	public static void  main(String[] args) {
		int[] ratings={1,2,3,1,2,4,3,5,1};
		System.out.println("The minimum # of candies is: "+candy(ratings));
	}
}
