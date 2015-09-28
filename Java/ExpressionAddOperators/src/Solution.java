import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	public static List<String> addOperators(String num, int target) {
        List<String> result=new ArrayList<>();
        if(num.length()==0) return result;
        add(num, target, result, 0, "", 0, 0);
        return result;
    }
	
	private static void add(String num, int target, List<String> result, int idx, String s, long evaluation, long multed){
		if(idx==num.length()){
			if(evaluation==target)
				result.add(s);
			return;
		}
		
		for(int i=idx; i<num.length(); i++){
			if(i!=idx && num.charAt(idx)=='0') break;
			long cur = Long.parseLong(num.substring(idx, i + 1));
            if(idx == 0){
                add(num, target, result, i+1, s+cur, cur, cur);
            }
            else{
            	add(num, target, result, i+1, s+"+"+cur, evaluation+cur, cur);
            	add(num, target, result, i+1, s+'-'+cur, evaluation-cur, -cur);
            	add(num, target, result, i+1, s+'*'+cur, evaluation-multed+multed*cur, multed*cur);
            }
		}
	}
	
	public static void main(String[] args) {
		String[] strs={"123","232","105","00","3456237490"};
		int[] targets={6,8,5,0,9191};
		System.out.println("The results are: ");
		for(int i=0; i<strs.length; i++){
			System.out.println("Expression: "+strs[i]+", target: "+targets[i]);
			System.out.println("Possible operations are: "+Arrays.deepToString(addOperators(strs[i], targets[i]).toArray()));
		}
	}
}
