import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class Solution {
	//Strobogrammatic Number I
	public static boolean isStrobogrammatic(String num){
		int len=num.length();
		String stroboCombination="00 11 88 696";
		int start=0;
		int end=len-1;
		while(start<=end){
			if(!stroboCombination.contains(num.charAt(start)+""+num.charAt(end)))
				return false;
			start++;
			end--;
		}
		return true;
	}

	//Strobogrammatic Number II
	public static List<String> findStrobogrammatic(int n) {
        List<String> result=new ArrayList<>();
        StringBuffer str=new StringBuffer();
        str.setLength(n);
        generateStrobogrammatic(result, str, 0, n-1);
        return result;
    }
	
	private static void generateStrobogrammatic(List<String> result, StringBuffer str, int left, int right){
		if(left>right){
			result.add(new String(str.toString()));
			return;
		}
		else if(left==right){
			str.setCharAt(left, '0');
			generateStrobogrammatic(result, str, left+1, right-1);
			str.setCharAt(left, '1');
			generateStrobogrammatic(result, str, left+1, right-1);
			str.setCharAt(left, '8');
			generateStrobogrammatic(result, str, left+1, right-1);
		}
		else{
			if(left!=0){
				str.setCharAt(left, '0');
				str.setCharAt(right, '0');
				generateStrobogrammatic(result, str, left+1, right-1);
			}
			
			str.setCharAt(left, '1');
			str.setCharAt(right, '1');
			generateStrobogrammatic(result, str, left+1, right-1);
			
			str.setCharAt(left, '8');
			str.setCharAt(right, '8');
			generateStrobogrammatic(result, str, left+1, right-1);
			
			str.setCharAt(left, '6');
			str.setCharAt(right, '9');
			generateStrobogrammatic(result, str, left+1, right-1);
			
			str.setCharAt(left, '9');
			str.setCharAt(right, '6');
			generateStrobogrammatic(result, str, left+1, right-1);
		}
	}
	
	//Strobogrammatic Number III
	public static int strobogrammaticInRange(String low, String high) {
		HashMap<Character, Character> hmap=new HashMap<>();
		hmap.put('0', '0');
		hmap.put('1', '1');
		hmap.put('8', '8');
		hmap.put('9', '6');
		hmap.put('6', '9');
		int result=0;
		for(int n=low.length(); n<=high.length(); n++){
			int[] count=new int[1];
			getCount(hmap, new char[n], count, low, high, 0, n-1);
			result+=count[0];
		}
		return result;
    }
	
	private static void getCount(HashMap<Character, Character> hmap, char[] str, int[] count, String low, String high, int start, int end){
		if(start>end){
			if((str.length==1 || str[0]!='0') && compare(low, new String(str)) && compare(new String(str), high))
				count[0]++;
			return;
		}
		
		for(char key:hmap.keySet()){
			str[start]=key;
			str[end]=hmap.get(key);
			if((start==end && key==hmap.get(key)) || (start<end))
				getCount(hmap, str, count, low, high, start+1, end-1);
		}
	}
	
	private static boolean compare(String a, String b){
	    if(a.length() != b.length())
	        return a.length() < b.length();
	    int i = 0;
	    while(i < a.length() &&a.charAt(i) == b.charAt(i))
	        i++;
	    return i == a.length() ? true: a.charAt(i) <= b.charAt(i);
	}
	
	//Main Method
	public static void main(String[] args){
		String num="9116";
		if(isStrobogrammatic(num))
			System.out.println(num+" is a strobogrammatic number.");
		else
			System.out.println(num+" is not a strobogrammatic number.");
		int n=7;
		System.out.println("All strobogrammatic numbers with "+n+" digits are: "+Arrays.deepToString(findStrobogrammatic(n).toArray()));
		//System.out.println(findStrobogrammatic(n).size());
		String low="50";
		String high="100";
		System.out.println("There are "+strobogrammaticInRange(low, high)+" strobogrammatic numbers between "+low+" - "+high+" inclusively");
	}
}
