import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class Solution {
	public static String alienOrder(String[] words) {
        int n=words.length;
        if(n==0) return "";
        
        //Count number of distinct alphabets
        List<Character> alphabets=new ArrayList<>();
        for(int i=0; i<n; i++){
        	String word=words[i];
        	for(int j=0; j<word.length(); j++){
        		if(!alphabets.contains(word.charAt(j)))
        			alphabets.add(word.charAt(j));
        	}
        }
        
        //Create an empty graph
        List<List<Integer>> adjacentList=new ArrayList<List<Integer>>();
        for(int i=0; i<26; i++)
        	adjacentList.add(new ArrayList<Integer>());
        
        //Compare two adjacent words in words
        for(int i=0; i<n-1; i++){
        	String word1=words[i];
        	String word2=words[i+1];
        	for(int j=0; j<Math.min(word1.length(), word2.length()); j++){
        		char c1=word1.charAt(j);
        		char c2=word2.charAt(j);
        		if(c1!=c2){
        			adjacentList.get(c1-'a').add(c2-'a');
        			break;
        		}
        	}
        }
        
        //If graph has cycle, not a valid alphabetic order
        if(hasCycle(adjacentList)) return "";
        
        Stack<Character> stack=new Stack<>();
        topologicalSort(stack, adjacentList);
        StringBuffer order=new StringBuffer();
        while(!stack.isEmpty())
        	order.append(stack.pop());
        for(char c:alphabets){
        	char[] cc=new char[1];
        	cc[0]=c;
        	if(!order.toString().contains(new String(cc)))
        		order.append(c);
        }
        return order.toString();
    }
	
	private static void topologicalSort(Stack<Character> stack, List<List<Integer>> adjacentList){
		boolean[] visited=new boolean[26];
		for(int i=0; i<26; i++){
			if(adjacentList.get(i).size()>0){
				if(!visited[i])
					sortUntil(stack, adjacentList, i, visited);
			}
		}
	}
	
	private static void sortUntil(Stack<Character> stack, List<List<Integer>> adjacentList, int v, boolean[] visited){
		visited[v]=true;
		for(Integer i:adjacentList.get(v))
			if(!visited[i])
				sortUntil(stack, adjacentList, i, visited);
		stack.push((char) (v+'a'));
	}
	
	private static boolean hasCycle(List<List<Integer>> adjacentList){
		boolean[] visited=new boolean[26];
		boolean[] stack=new boolean[26];
		for(int i=0; i<26; i++){
			if(adjacentList.get(i).size()>0){
				if(detectCycle(adjacentList, i, visited, stack))
					return true;
			}
		}
		return false;
	}
	
	private static boolean detectCycle(List<List<Integer>> adjacentList, int v, boolean[] visited, boolean[] stack){
		if(!visited[v]){
			visited[v]=true;
			stack[v]=true;
			for(Integer i:adjacentList.get(v)){
				if(!visited[i] && detectCycle(adjacentList, i, visited, stack))
					return true;
				else if(stack[i])
					return true;
			}
		}
		stack[v]=false;
		return false;
	}
	
	public static void main(String[] args) {
	String[] words={"aa","abb","aba"};
		//String[] words={"wrt","wrf","er","ett","rftt"};
		System.out.println("Given sequence of words is: "+Arrays.toString(words));
		System.out.println("The dictionary is: "+alienOrder(words));
	}
}
