import java.util.Arrays;

public class Solution {
	 public static int trap(int[] height) {
		 int n=height.length;
		 if(n==0) return 0;
		 int[] rainLeft=new int[n];
		 int[] rainRight=new int[n];
		
		 int trapped=height[0];
		 rainLeft[0]=0;
		 for(int i=1; i<n; i++){
			 rainLeft[i]=trapped;
			 trapped=Math.max(trapped, height[i]);
		 }
		
		 trapped=height[n-1];
		 rainRight[n-1]=0;
		 for(int i=n-2; i>=0; i--){
			 rainRight[i]=trapped;
			 trapped=Math.max(trapped, height[i]);
		 }
		 
		 int[] rain=new int[n];
		 trapped=0;
		 for(int i=0; i<n; i++){
			 rain[i]=Math.min(rainLeft[i], rainRight[i])-height[i];
			 trapped+=(rain[i]>0)?rain[i]:0;
		}
		 return trapped;
	 }
	 
	 public static void main(String[] args){
		 int[] height={0,1,0,2,1,0,1,3,2,1,2,1};
		 System.out.println("Rain Trapped:"+trap(height));
	 }
}
