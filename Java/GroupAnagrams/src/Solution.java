import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class Solution {
	public static List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result=new ArrayList<List<String>>();
        int n=strs.length;
        if(n==0) return result;
        HashMap<String, ArrayList<Integer>> index=new HashMap<>();
        for(int i=0; i<n; i++){
        	char[] cc=strs[i].toCharArray();
        	Arrays.sort(cc);
        	String word=String.valueOf(cc);
        	if(!index.containsKey(word)){
        		ArrayList<Integer> l=new ArrayList<>();
        		l.add(i);
        		index.put(word, l);
        	}
        	else
        		index.get(word).add(i);
        }

        
        for(String key:index.keySet()){
        	List<String> l=new ArrayList<>();
        	for(int i:index.get(key))
        		l.add(strs[i]);
        	Collections.sort(l);	//Sort each list in alphabetic order
        	result.add(l);
        }
        	
        return result;
    }
	
	public static void main(String[] args) {
		String[] strs={"eat","tea","tan","ate","nat","bat","tab"};
		System.out.print("The string is: ");
		for(String ss:strs)
			System.out.print("'"+ss+"' ");
		System.out.println();
		System.out.println("Groups of anagrams:");
		for(List<String> str:groupAnagrams(strs))
			System.out.println(Arrays.deepToString(str.toArray()));
	}
}
