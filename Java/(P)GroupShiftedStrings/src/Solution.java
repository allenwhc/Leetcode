import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class Solution {
	public static List<List<String>> groupStrings(String[] strings){
		List<List<String>> allGroups=new ArrayList<List<String>>();
		
		//Use hash string
		HashMap<String, List<String>> map=new HashMap<>();
		for(String str: strings){
			if(!map.containsKey(hashStr(str))){
				List<String> l=new ArrayList<String>();
				l.add(str);
				map.put(hashStr(str), l);
			}
			else
				map.get(hashStr(str)).add(str);
		}
		
		
		for(String key:map.keySet()){
			Collections.sort(map.get(key));	//Sort to make sure each list is in lexicographic order
			allGroups.add(new ArrayList<String>(map.get(key)));
		}
		return allGroups;
	}
	
	//Convert string to hash string
	private static String hashStr(String s){
		if(s.length()==0) return "";
		char base=s.charAt(0);
		StringBuffer str=new StringBuffer(s);
		for(int i=0; i<s.length(); i++){
			char c=s.charAt(i);
			str.setCharAt(i, (char)('a'+(c-base>=0?c-base:c-base+26)));
		}
		return str.toString();
	}
	
	public static void main(String[] args) {
		//String[] strings={"fpbnsbrkbcyzdmmmoisaa", "cpjtwqcdwbldwwrryuclcngw", "a", "fnuqwejouqzrif", "js", "qcpr", "zghmdiaqmfelr", "iedda", "l", "dgwlvcyubde", "lpt", "qzq", "zkddvitlk", "xbogegswmad", "mkndeyrh", "llofdjckor", "lebzshcb", "firomjjlidqpsdeqyn", "dclpiqbypjpfafukqmjnjg", "lbpabjpcmkyivbtgdwhzlxa", "wmalmuanxvjtgmerohskwil", "yxgkdlwtkekavapflheieb", "oraxvssurmzybmnzhw", "ohecvkfe", "kknecibjnq", "wuxnoibr", "gkxpnpbfvjm", "lwpphufxw", "sbs", "txb", "ilbqahdzgij", "i", "zvuur", "yfglchzpledkq", "eqdf", "nw", "aiplrzejplumda", "d", "huoybvhibgqibbwwdzhqhslb", "rbnzendwnoklpyyyauemm"};
		String[] strings={"aa","a","bb"};
		System.out.println("The input string array is: " +Arrays.toString(strings));
		System.out.println("The grouped shifted strings is: ");
		for(List<String> l:groupStrings(strings))
			System.out.println(Arrays.deepToString(l.toArray()));
	}
}