import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Solution {
	//Word Ladder II
	public static List<List<String>> findLadders(String beginWord, String endWord, Set<String> wordList) {
        List<List<String>> allSols=new ArrayList<List<String>>();
        
    }
	
	public static void main(String[] args) {
		String beginWord="hit";
		String endWord="cog";
		Set<String> wordList=new HashSet<>();
		String[] words={"hot","dot","dog","lot","log"};
		for(String s:words)
			wordList.add(s);
		System.out.print("The word list is: ");
		for(String s:wordList)
			System.out.print(s+",");
		System.out.println("The word path is: ");
		for(List<String> l:findLadders(beginWord, endWord, wordList))
			System.out.println(Arrays.deepToString(l.toArray()));
	}
}
