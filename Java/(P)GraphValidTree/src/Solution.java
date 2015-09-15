import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	public static boolean validTree(int n, int[][] edges){
		List<List<Integer>> adjacentList=new ArrayList<List<Integer>>();
		for(int i=0; i<n; i++)
			adjacentList.add(new ArrayList<>());
		//Construct adjacent list according to edges
		for(int i=0; i<edges.length; i++){
			int u=edges[i][0];	//Departure node
			int v=edges[i][1];	//Destination node
			adjacentList.get(u).add(v);
			adjacentList.get(v).add(u);	//Undirected graph needs to update the inverted case
		}
		boolean[] visited=new boolean[n];
		
		//Recursively check if there's cycle in graph
		if(hasCycle(adjacentList, 0, visited, -1))
			return false;
		
		//Check if any node is unvisited
		for(int i=0; i<n; i++)
			if(!visited[i]) return false;
		return true;
	}
	
	private static boolean hasCycle(List<List<Integer>> adjacentList, int u, boolean[] visited, int parent){
		visited[u]=true;	//Mark node u as visited
		for(int i=0; i<adjacentList.get(u).size(); i++){
			int v=adjacentList.get(u).get(i);
			if((visited[v] && parent!=v) || (!visited[v] && hasCycle(adjacentList, v, visited, u)))
				return true;
		}
		return false;
	}
	
	public static void main(String[] args) {
		int n=5;
		int[][] edges={{0,1},{0,2},{0,3},{1,4}};
		System.out.print("Suppose given "+n+" nodes and connection map ");
		for(int[] e:edges)
			System.out.print(Arrays.toString(e)+",");
		System.out.println();
		if(validTree(n, edges))
			System.out.println("It's a valid tree.");
		else
			System.out.println("It's not a valid tree.");
	}
}