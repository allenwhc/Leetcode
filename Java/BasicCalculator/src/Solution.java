import java.util.Stack;

public class Solution {
	public static int calculate(String s) {
        int n=s.length();
        if(n==0) return 0;
        boolean positive=true;
        boolean prevPositive=true;
        int result=0;
        Stack<Boolean> stack=new Stack<>();
        for(int i=0; i<n; i++){
        	char c=s.charAt(i);
        	if(c==' ') continue;
        	if(c=='+') positive=true;
        	else if(c=='-') positive=false;
        	else if (c=='(') {
        		stack.push(prevPositive);
        		prevPositive=(positive==true)?prevPositive:!prevPositive;
        		positive=true;
			}
        	else if(c==')'){
        		prevPositive=stack.pop();
        		positive=true;
        	}
        	else{
        		int num=0;
        		while(i<n && Character.isDigit(s.charAt(i))){
        			num=num*10+s.charAt(i)-'0';
        			i++;
        		}
        		i--;

        		result+=(positive==prevPositive)?num:-num;
        	}
        	//System.out.println(result);
        }
        return result;
    }
	
	public static void main(String[] args) {
		String s="1-1";
		System.out.println("The calculating result of '"+s+"' is: "+calculate(s));
	}
}