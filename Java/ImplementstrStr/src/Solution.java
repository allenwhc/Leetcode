
public class Solution {
	public static int strStr (String haystack, String needle) {
        int idx=-1;
        idx=haystack.indexOf(needle, idx);
        return idx;
    }
	public static void main(String[] args) {
		String haystack="asfdaosvbouefe";
		String needle="dao";
		System.out.println("The first occurrence of '"+needle+"' in '"+haystack+"' is:"+strStr(haystack, needle));
	}
}
