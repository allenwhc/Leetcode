import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Solution {
	//Word Break I
	public static boolean wordBreak(String s,  Set<String> wordDict){
		int n=s.length();
		if(n==0) return wordDict.size()==0;
		boolean[] isBreak=new boolean[n+1];
		for(int i=0; i<=n; i++)
			isBreak[i]=false;
		isBreak[0]=true;
		for(int i=1; i<=n; i++){
			if(isBreak[i]==false && wordDict.contains(s.substring(0, i)))
				isBreak[i]=true;
			if(isBreak[i]==true){
				if(i==n) return true;
				for(int j=i+1; j<=n; j++){
					if(isBreak[j]==false && wordDict.contains(s.substring(i,j)))
						isBreak[j]=true;
					if(j==n && isBreak[j]==true) return true;
				}
			}
		}
		return false;
		
	}

	//Word Break II
	public static List<String> wordBreak2(String s, Set<String> wordDict){
		List<String> result=new ArrayList<>();
		StringBuffer str=new StringBuffer();
		int n=s.length();
		if(n==0) return result;
		boolean[] w=new boolean[n+1];
		for(int i=0; i<=n; i++)
			w[i]=true;
		breakdown(result, wordDict, s, str, 0, n, w);
		return result;
	}
	
	private static void breakdown(List<String> result ,Set<String> wordDict, String s, StringBuffer str, int step, int length, boolean[] w){
		if(step==length){
			result.add(str.substring(0,str.length()-1));
			return;
		}
		
		for(int i=step; i<length; i++){
			String segment=s.substring(step, i+1);
			if(w[i+1]==true && wordDict.contains(segment)){
				str.append(segment).append(" ");
			int size=result.size();
			breakdown(result, wordDict, s, str, i+1, length, w);
			if(size==result.size()) w[i+1]=false;
			str.setLength(str.length()-segment.length()-1);
			}
		}
	}
	
	public static void main(String[] args){
		String s="catsanddog";
		Set<String> wordDict=new HashSet<String>();
		wordDict.add("cat");
		wordDict.add("cats");
		wordDict.add("and");
		wordDict.add("sand");
		wordDict.add("dog");
		System.out.println("The dictionary is:"+Arrays.deepToString(wordDict.toArray()));
		if(wordBreak(s, wordDict))
			System.out.println("'"+s+"' is a word break in above dictionary");
		else
			System.out.println("'"+s+"' is a word break in above dictionary");
		System.out.println("All possible word breakdowns is: "+Arrays.deepToString(wordBreak2(s, wordDict).toArray()));
	}
}
