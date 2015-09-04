
public class Solution {
	public static int minDistance(String word1, String word2) {
        int m=word1.length();
        int n=word2.length();
        if(m==0) return n;
        else if(n==0) return m;
        int[][] distance=new int[m+1][n+1];
        
        for(int i=0; i<=m; i++)
        	distance[i][0]=i;
        for(int j=0; j<=n; j++)
        	distance[0][j]=j;
        
        for(int i=0; i<m; i++){
        	for(int j=0; j<n; j++){
        		char c1=word1.charAt(i);
        		char c2=word2.charAt(j);
        		if(c1==c2)
        			distance[i+1][j+1]=distance[i][j];
        		else{
        			int replacement=distance[i][j]+1;
        			int deletion=distance[i+1][j]+1;
        			int insertion=distance[i][j+1]+1;
        			distance[i+1][j+1]=Math.min(replacement, Math.min(deletion, insertion));
        		}
        	}
        }
        return distance[m][n];
    }
	
	public static void main(String[] args) {
		String word1="scared";
		String word2="sacred";
		System.out.println("The minimum distance between '"+word1+"' and '"+word2+"' is: "+minDistance(word1, word2));
	}
}
