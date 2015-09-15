import java.util.Arrays;
import java.util.Comparator;

public class Solution {
	public static String largestNumber(int[] nums){
		StringBuffer result=new StringBuffer();
		String[] strs=new String[nums.length];
		for(int i=0; i<nums.length; i++)
			strs[i]=String.valueOf(nums[i]);
		Arrays.sort(strs, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				Long n1=Long.valueOf(o1+o2);
				Long n2=Long.valueOf(o2+o1);
				return n2.compareTo(n1);
			}
		});

		for(String s:strs)
			result.append(s);
		if(result.toString().charAt(0)=='0') return "0";
		return result.toString();
	}
	
	public static void main(String[] args) {
		int[] nums={999999998,999999997,999999999};
		System.out.println("The largest number is: "+largestNumber(nums));
	}
}