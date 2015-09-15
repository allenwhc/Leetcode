import java.util.ArrayList;
import java.util.List;

public class VersonControl {
	private static List<Integer> versions=new ArrayList<>();
	public VersonControl(int n, int k){
		for(int i=0; i<k; i++)
			versions.add(1);
		for(int i=k; i<n; i++)
			versions.add(0);
	}
	public static boolean isBadVersion(int version){
		return versions.get(version)==0;
	}
	public static class Solution extends VersonControl{
		public Solution(int n, int k){
			super(n,k);
		}
		public static int firstBadVersion(int n){
			if(n==0) return 0;
			int start=1;
			int end=n;
			while(start<end){
				int middle=start+(end-start)/2;
				if(isBadVersion(middle))
					end=middle;
				else
					start=middle+1;
			}
			return start;
		}
	}
	
	public static void main(String[] args) {
		int n=2126753390;
		int k=1702766719;
		VersonControl vc=new VersonControl(n,k);
		System.out.println("First bad version is: "+Solution.firstBadVersion(n));
	}
}
