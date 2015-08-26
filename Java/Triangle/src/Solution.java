import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class Solution {
	public static int minimumTotal(List<List<Integer>> triangle) {
		int m=triangle.size();
        if(m==0) return 0;
        int[] pathSum=new int[m];
        for(int i=0; i<m; i++){
        		pathSum[i]=triangle.get(m-1).get(i);
        }
        for(int i=m-2; i>=0; i--){
        	int n=triangle.get(i).size();
        	for(int j=0; j<n; j++){
        		pathSum[j]=Math.min(pathSum[j], pathSum[j+1])+triangle.get(i).get(j);
        		//System.out.println(Arrays.toString(pathSum));
        	}
        }
        return pathSum[0];
    }
	
	public static void  main(String[] args) {
		List<List<Integer>> triangle=new ArrayList<List<Integer>>();
		triangle.add(Arrays.asList(-1));
		triangle.add(Arrays.asList(2,3));
		triangle.add(Arrays.asList(1,-1,-3));
		//triangle.add(Arrays.asList(4,1,8,3));
		System.out.println("The triangle is: ");
		for(List<Integer> l:triangle)
			System.out.println(Arrays.deepToString(l.toArray()));
		System.out.println("Minimum path sum is: "+minimumTotal(triangle));
	}
}
