import java.util.ArrayList;
import java.util.List;

public class Relation {
	private static List<List<Integer>> adjacencyList=new ArrayList<List<Integer>>();
	public Relation(int[][] matrix){
		for(int i=0; i<matrix.length; i++){
			List<Integer> l=new ArrayList<>();
			for(int j=0; j<matrix[i].length; j++){
				l.add(matrix[i][j]);
			}
			adjacencyList.add(l);
		}
	}
	
	public static boolean knows(int a, int b){
		return adjacencyList.get(a).get(b)==1?true:false;
	}
	
	public static class Solution extends Relation{
		private static int[][] matrix=new int[100][100];

		public Solution(){
			super(matrix);
		}
		
		public static int findCelebrity(int n){
			if(n<=0) return -1;
			else if(n==1) return 0;
			for(int i=0, j=0; i<n; i++){
				for(j=0; j<n; j++){
					if(i!=j && knows(i, j)) break;	//If i knows any of j, i is not a celebrity
					if(i!=j && !knows(j, i)) break;	//If any of j doesn't know i, i is not a celebrity
				}
				//j=n means i doesn't know any of j, and all j know i, thus i is a celebrity
				if(j==n) return i;
			}
			return -1;
		}
	}
	
	public static void main(String[] args) {
		int[][] matrix={{1,0,1,0},{0,1,1,0},{0,0,1,0},{0,0,1,1}};
		Relation r=new Relation(matrix);
		System.out.println("The celebrity is: "+Solution.findCelebrity(matrix.length));
	}
}
