import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.lang.StringBuilder;

public class Solution{
	public static List<String> fullJustify(String[] words, int maxWidth){
		List<String> result=new ArrayList<String>();
		if(words.length==0) return result;
		List<Integer> lv=new ArrayList<Integer>();
		int i=0;
		int len=0;
		int end=-1;
		while(i<words.length){
			while(i<words.length && len+words[i].length()<=maxWidth){
				len+=words[i++].length()+1;
			}
			i--;
			len--;

			StringBuilder str=new StringBuilder();
			int avgSpace=0;
			int leftSpace=0;

			if(i==words.length-1 || i==end+1)
				avgSpace=leftSpace=0;
			else{
				avgSpace=(maxWidth-len)/(i-end-1);
				leftSpace=(maxWidth-len)%(i-end-1);
			}

			for(int j=end+1; j<i; j++){
				str.append(words[j]);
				for(int k=0; k<=avgSpace; k++)
					str.append(" ");
				if(leftSpace!=0){
					str.append(" ");
					leftSpace--;
				}
			}

			str.append(words[i]);
			for(int j=0; j<maxWidth-str.length(); j++)
				str.append(" ");
			result.add(str.toString());
			end=i++;
			len=0;

		}

		return result;
	}

	public static void main(String[] args) {
		//String[] words={"This", "is", "an", "example", "of", "text", "justification."};
		String[] words={""};
		int maxWidth=2;
		System.out.println("The justified text is: "+Arrays.deepToString(fullJustify(words,maxWidth).toArray()));
	}
}