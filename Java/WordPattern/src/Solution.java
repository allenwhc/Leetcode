import java.util.HashMap;

public class Solution {
	public static boolean wordPattern(String pattern, String str){
		String[] strs=str.split(" ");
		if(strs.length!=pattern.length()) return false;
		if(pattern.length()==1) return true;
		HashMap<String, Character> map=new HashMap<String, Character>();
		for(int i=0; i<strs.length; i++){
			char currPattern=pattern.charAt(i);
			String word=strs[i];
			if(map.containsKey(word)){
				if(map.get(word)!=currPattern) return false;
			}
			else{
				for(Character c:map.values())
					if(c==currPattern) return false;
				map.put(word,currPattern);
			}
		}
		
		return true;
	}
	
	public static void main(String[] args) {
		String[] patterns={"abba","abab","aaaa","aabb"};
		String[] strs={"dog cat cat dog","dog cat dog cat", "dog dog dog cat","dog dog cat cat"};
		for(int i=0; i<patterns.length; i++){
			if(wordPattern(patterns[i], strs[i]))
				System.out.println("'"+strs[i]+"' fits pattern '"+patterns[i]+"'.");
			else
				System.out.println("'"+strs[i]+"' doesn't fit pattern '"+patterns[i]+"'.");
		}
	}
}
