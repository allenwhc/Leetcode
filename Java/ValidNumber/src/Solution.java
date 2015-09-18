
public class Solution {
	public static boolean isNumber(String s) {
        int len=s.length();
        if(len==0) return false;
        else if(len==1 && !Character.isDigit(s.charAt(0))) return false;
        int i=0;
        //1. Skip front spaces
        while(i<len && s.charAt(i)==' ') i++;
        	
        //2. Check if has sign
        if(s.charAt(i)=='+' || s.charAt(i)=='-') i++;

        //3. Check # of digits
        int noPts=0;
        int noDgts=0;
        while(i<len && (s.charAt(i)=='.' || Character.isDigit(s.charAt(i)))){
        	if(s.charAt(i)=='.') noPts++;
        	else noDgts++;
        	i++;
        }
        if(noDgts<1 || noPts>1) return false;
        
        //4. Check exponential part
        noDgts=0;
        if(i<len && s.charAt(i)=='e'){
        	i++;
        	if(i<len && (s.charAt(i)=='+' || s.charAt(i)=='-')) i++;
        	while(i<len && Character.isDigit(s.charAt(i))){
        		noDgts++;
        		i++;
        	}
        	if(noDgts<1) return false;
        }

        //5. Skip trailing spaces
        while(i<len && s.charAt(i)==' ') i++;
        return i==len;
    }
	
	public static void main(String[] args) {
		String[] s={"0"," 0.1 ","abc","1 a","2e10","0e"};
		boolean[] num=new boolean[s.length];
		for(int i=0; i<s.length; i++){
			num[i]=isNumber(s[i]);
			if(num[i])
				System.out.println("'"+s[i]+"' is a number");
			else
				System.out.println("'"+s[i]+"' is not a number");
		}
	}
}
