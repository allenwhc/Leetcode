import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	public static List<String> restoreIPAddresses(String s){
		List<String> ip=new ArrayList<>();
		int n=s.length();
		for(int i=1; i<=3; i++){
			if(n-i>9) continue;
			for(int j=i+1; j<=i+3; j++){
				if(n-j>6) continue;
				for(int k=j+1; k<=j+3 && k<n; k++){
					int a,b,c,d;
					a=Integer.parseInt(s.substring(0,i));
					b=Integer.parseInt(s.substring(i,j));
					c=Integer.parseInt(s.substring(j,k));
					d=Integer.parseInt(s.substring(k));
					if(a>255 || b>255 || c>255 || d>255) continue;
					StringBuffer str=new StringBuffer();
					str.append(a).append(".").append(b).append(".").append(c).append(".").append(d);
					if(str.length()<n+3) continue;
					ip.add(str.toString());
				}
			}
		}
		return ip;
	}
	public static void main(String[] args) {
		String s="25525511135";
		System.out.println("The restored IP addresses of "+s+" is: "+Arrays.deepToString(restoreIPAddresses(s).toArray()));
	}
}
