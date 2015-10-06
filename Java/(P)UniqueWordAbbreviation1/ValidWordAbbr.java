import java.lang.StringBuilder;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashMap;

public class ValidWordAbbr{
	private static HashMap<String,List<String>> map;
	public ValidWordAbbr(String[] dictionary){
		String[] abbr=new String[dictionary.length];
		map=new HashMap<String,List<String>>();
		int n=dictionary.length;
		for(int i=0; i<n; i++){
			abbr[i]=abbreviation(dictionary[i]);
			if(map.containsKey(abbr[i]))
				map.get(abbr[i]).add(dictionary[i]);
			else 
				map.put(abbr[i], new ArrayList<String>(Arrays.asList(dictionary[i])));
		}


	}
	
	public static boolean isUnique(String word){
		String str=abbreviation(word);
		if(!map.containsKey(str) || (map.get(str).size()==1 && map.get(str).get(0).equals(word))) return true;
		if(map.get(str).size()>=1) return false;
		return true;
	}

	private static String abbreviation(String word){
		StringBuilder str=new StringBuilder();
		str.append(word.charAt(0));
		int count=word.length()-2;
		if(count>0) str.append(count);
		if(word.length()>=2) str.append(word.charAt(word.length()-1));
		return str.toString();
	}

	public static void print(){
	// 	System.out.print("The abbreviated words in dictionary are: ");
	// 	for(String s:abbr)
	// 		System.out.print(s+",");
		System.out.println("The hash table of dictionary is: ");
		for(String s:map.keySet())
			System.out.println(s+":"+Arrays.deepToString(map.get(s).toArray()));
	}

	public static void main(String[] args){
		String[] dictionary={"deer","door","cake","card"};
		ValidWordAbbr wordAbbr=new ValidWordAbbr(dictionary);
		wordAbbr.print();
		String[] words={"dear","cart","cane","make"};
		for(int i=0; i<words.length; i++){
			if(wordAbbr.isUnique(words[i]))
				System.out.println("'"+words[i]+"' has unique abbreviation in dictionary.");
			else
				System.out.println("'"+words[i]+"' doesn't have unique abbreviation in dictionary.");
		}
	}
}