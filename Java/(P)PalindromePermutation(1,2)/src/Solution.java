import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class Solution {
	//Palindrome permutation I
	public static boolean canPermutation(String s){
		int len=s.length();
		if(len<=1) return true;
		HashMap<Character, Integer> charFrequency=new HashMap<>();
		for(int i=0; i<len; i++){
			char c=s.charAt(i);
			if(charFrequency.containsKey(c))
				charFrequency.put(c,charFrequency.get(c)+1);
			else
				charFrequency.put(c, 1);
		}
		int countOdd=0;
		if(len%2!=0){
			//Length is odd, only one character can appear once
			for(int value:charFrequency.values())
				if(value%2!=0)
					countOdd++;
			if(countOdd>1) return false;
		}
		else{
			for(int value:charFrequency.values())
				if(value%2!=0)
					countOdd++;
			if(countOdd>0) return false;
		}
		return true;
	}
	
	//Palindrome Permutation II
	public static List<String> generatePalindromes(String s){
		List<String> result=new ArrayList<>();
		if(s.length()<=1){
			result.add(s);
			return result;
		}
		HashMap<Character, Integer> hmap=new HashMap<>();
		for(int i=0; i<s.length(); i++){
			char c=s.charAt(i);
			if(!hmap.containsKey(c))
				hmap.put(c, 1);
			else
				hmap.put(c, hmap.get(c)+1);
		}
		
//		for(char c:hmap.keySet())
//			System.out.println(hmap.get(c));
		StringBuffer str=new StringBuffer();
		int countOdd=0;
		//Traverse hash table
		for(char key:hmap.keySet()){
			if(hmap.get(key)%2!=0){
				if(++countOdd==2) return result;	//The string doesn't have palindrome permutation
				str.append(key);
			}
		}
		permutation(result, str, hmap, countOdd);
		return result;
	}
	
	private static void permutation(List<String> result, StringBuffer str, HashMap<Character, Integer> hmap, int odd){
		boolean flag=true;
		for(char key:hmap.keySet()){
			if(hmap.get(key)>1){
				flag=false;
				hmap.put(key, hmap.get(key)-2);	
				str.append(key);	//Add character to string
				permutation(result, str, hmap, odd);
				str.deleteCharAt(str.length()-1);
				hmap.put(key, hmap.get(key)+2);	
			}
		}
		if(flag){
			StringBuffer s=new StringBuffer(str.substring(odd, str.length()));
			s.reverse();
			result.add(s.toString()+str.toString());
		}
	}
	
	public static void main(String[] args){
		String s="aab";
		if(canPermutation(s))
			System.out.println("'"+s+"' has palindrome permutation.");
		else
			System.out.println("'"+s+"' doesn't have palindrome permutation.");
		System.out.println("All palindrom permutations of '"+s+"' are: "+Arrays.deepToString(generatePalindromes(s).toArray()));
	}
}
