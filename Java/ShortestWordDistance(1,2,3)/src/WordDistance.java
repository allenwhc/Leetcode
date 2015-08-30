import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class WordDistance {
	//Shortest Word Distance I
		public static int shortestDistance(String[] words, String word1, String word2){
			int n=words.length;
			if(n==0) return 0;
			HashMap<String, List<Integer>> hmap=new HashMap<>();
			for(int i=0; i<n; i++){
				String word=words[i];
				if(!hmap.containsKey(word)){
					List<Integer> index=new ArrayList<>();
					index.add(i);
					hmap.put(word, index);
				}
				else
					hmap.get(word).add(i);
			}
			
			int minDistance=Integer.MAX_VALUE;
			for(int i:hmap.get(word1))
				for(int j:hmap.get(word2))
					minDistance=Math.min(minDistance, Math.abs(i-j));
			return minDistance;
		}
	//Shortest Word Distance II
		private HashMap<String, List<Integer>> wordsIndex=new HashMap<>();
		public WordDistance(String[] words){
			for(int i=0; i<words.length; i++){
				if(!wordsIndex.containsKey(words[i])){
					List<Integer> index=new ArrayList<>();
					index.add(i);
					wordsIndex.put(words[i], index);
				}
				else
					wordsIndex.get(words[i]).add(i);
			}
		}
		
		public int shortest(String word1, String word2){
			int minDistance=Integer.MAX_VALUE;
			for(int i:wordsIndex.get(word1))
				for(int j:wordsIndex.get(word2))
					minDistance=Math.min(minDistance,Math.abs(i-j));
			return minDistance;
		}
		
		//Shortest Word Distance III
		
		public static int shortestWordDistance(String[] words, String word1, String word2){
			int n=words.length;
			if(n==0) return 0;
			HashMap<String, List<Integer>> hmap=new HashMap<>();
			for(int i=0; i<n; i++){
				String word=words[i];
				if(!hmap.containsKey(word)){
					List<Integer> index=new ArrayList<>();
					index.add(i);
					hmap.put(word, index);
				}
				else
					hmap.get(word).add(i);
			}
			
			int minDistance=Integer.MAX_VALUE;
			if(word1.equals(word2)){
				minDistance=hmap.get(word1).get(1)-hmap.get(word1).get(0);
				for(int i=1; i<hmap.get(word1).size(); i++)
					minDistance=Math.min(minDistance, hmap.get(word1).get(i)-hmap.get(word1).get(i-1));
			}
			else{
				for(int i:hmap.get(word1))
					for(int j:hmap.get(word2))
						minDistance=Math.min(minDistance, Math.abs(i-j));
			}
			return minDistance;
		}
		
		//Main method
		public static void main(String[] args){
			System.out.println("Shortest Word Distance I: ");
			String[] words={"practice","makes","perfect","coding","makes"};
			String word1_1="coding";
			String word1_2="makes";
			System.out.print("The words are: ");
			for(String s:words)
				System.out.print("'"+s+"' ");
			System.out.println();
			System.out.println("The shortest distance between '"+word1_1+"' and '"+word1_2+"' is: "+shortestDistance(words, word1_1, word1_2));
			System.out.println();
			System.out.println("Shortest Word Distance II: ");
			String[] words2={"a","a","b","b"};
			System.out.print("The words are: ");
			for(String s:words2)
				System.out.print("'"+s+"' ");
			System.out.println();
			WordDistance w=new WordDistance(words2);
			String word2_1="a";
			String word2_2="b";
			System.out.println("The shortest distance between '"+word2_1+"' and '"+word2_2+"' is: "+w.shortest(word2_1, word2_2));
			System.out.println("The shortest distance between '"+word2_2+"' and '"+word2_1+"' is: "+w.shortest(word2_2, word2_1));
			System.out.println();
			System.out.println("Shortest Word Distance III: ");
			String[] words3={"practice","makes","perfect","coding","makes"};
			String word3_1="makes";
			String word3_2="makes";
			System.out.print("The words are: ");
			for(String s:words3)
				System.out.print("'"+s+"' ");
			System.out.println();
			System.out.println("The shortest distance between '"+word3_1+"' and '"+word3_2+"' is: "+shortestWordDistance(words3, word3_1, word3_2));
		}
}
