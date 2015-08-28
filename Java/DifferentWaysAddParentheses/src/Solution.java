import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	public static List<Integer> diffWaysToCompute(String input) {
        List<Integer> result=new ArrayList<>();
        int n=input.length();
        if(n==0) return result;
        
        int index=0;
        int value=0;
        for(; index<n && Character.isDigit(input.charAt(index)); index++)
        	value=value*10+input.charAt(index)-'0';
        
        if(index==input.length()) {	
        	List<Integer> number=new ArrayList<>();
        	number.add(value);
        	return number;
        }
        
        
        List<Integer> leftPart=new ArrayList<>();
        List<Integer> rightPart=new ArrayList<>();
        for(int i=0; i<n; i++){
        	if(!Character.isDigit(input.charAt(i))){
        		leftPart=diffWaysToCompute(input.substring(0,i));
        		rightPart=diffWaysToCompute(input.substring(i+1,n));
        		for(int j=0; j<leftPart.size(); j++){
        			for(int k=0; k<rightPart.size(); k++){
        				switch (input.charAt(i)) {
						case '*':
							result.add(leftPart.get(j)*rightPart.get(k));
							break;
						case '+':
							result.add(leftPart.get(j)+rightPart.get(k));
							break;
						case '-':
							result.add(leftPart.get(j)-rightPart.get(k));
							break;
						default:
							break;
						}
        			}
        		}
        	}
        }
        
        	
        return result;
    }
	
	public static void main(String[] args){
		String input="2*3-4*5";
		System.out.println("The input expression is: "+input);
		System.out.println("Possible results are: "+Arrays.deepToString(diffWaysToCompute(input).toArray()));
	}
}
