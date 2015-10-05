import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class Solution {
	public static List<Integer> findSubstring(String s, String[] words) {
        List<Integer> index=new ArrayList<>();
        int n=words.length;
        int len=words[0].length();
        if(len==0) return index;
        HashMap<String, Integer> map=new HashMap<>();
        for(String word:words){
        	if(!map.containsKey(word))
        		map.put(word, 1);
        	else
        		map.put(word, map.get(word)+1);
        }
        
        int i=0; 
        while(i+n*len<=s.length()){
        	HashMap<String, Integer> map2=new HashMap<>(map);
        	int j=0;
        	while(j<n){
        		String str=s.substring(i+j*len, i+(j+1)*len);
        		if(map2.containsKey(str)){
        			map2.put(str,map2.get(str)-1);
        			if(map2.get(str)<0) break;
        		}
        		else break;
        		j++;
        	}
        	if(j==n) index.add(i);
        	i++;
        }
        return index;
    }
	
	public static void main(String[] args) {
		String s="barfoothefoobarman";
		String[] words={"foo","bar"};
		System.out.println("The starting indices are: "+Arrays.deepToString(findSubstring(s, words).toArray()));
	}
}