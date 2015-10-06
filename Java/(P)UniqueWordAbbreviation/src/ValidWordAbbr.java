
import java.lang.StringBuilder;

public class ValidWordAbbr {
	private static String[] abbr;
	public ValidWordAbbr(String[] dictionary){
		this.abbr=dictionary;
		int n=dictionary.length;
		for(int i=0; i<n; i++){
			String word=dictionary[i];
			int len=word.length();
			StringBuilder str=new StringBuilder();
			if(len<=2)
				abbr[i]=word;
			else{
				str.append(word.charAt(0)).append(len-2).append(word.charAt(len-1));
				abbr[i]=str.toString();
			}
		}
	}
	
	public static boolean isUnique(String word){
		int len=word.length();
		StringBuilder str=new StringBuilder();
		if(len<=2){
			for(String s:abbr)
				if(s.equals(word)) return false;
		}
		else{
			str.append(word.charAt(0)).append(len-2).append(word.charAt(len-1));
			String s=str.toString();
			for(String ss:abbr)
				if(ss.equals(s)) return false;
		}
		return true;
	}
	
	public static void print(){
		for(String s:abbr)
			System.out.println(s);
	}
	
	public static void main(String[] args) {
		String[] dictionary={"deer","me","cake","card"};
		ValidWordAbbr wordAbbr=new ValidWordAbbr(dictionary);
		wordAbbr.print();
		System.out.println(wordAbbr.isUnique("dear"));
		System.out.println(wordAbbr.isUnique("cart"));
		System.out.println(wordAbbr.isUnique("cane"));
		System.out.println(wordAbbr.isUnique("make"));
	}
}