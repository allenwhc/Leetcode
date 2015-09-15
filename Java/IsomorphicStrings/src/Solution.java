import java.util.HashMap;

public class Solution {
    public static boolean isIsomorphic(String s, String t) {
        if(s.length()==0) return t.length()==0;
        HashMap<Character, Character> map=new HashMap<>();
        for(int i=0; i<s.length(); i++){
        	char cs=s.charAt(i);
        	char ct=t.charAt(i);
        	if(!map.containsKey(cs)){
        		for(char val:map.values())
        			if(val==ct) return false;
        		map.put(cs, ct);
        	}
        	else{
        		if(ct!=map.get(cs))
        			return false;
        	}
        }
        return true;
    }
    
    public static void main(String[] args) {
		String[] s={"egg","foo","paper"};
		String[] t={"add","bar","title"};
		
		boolean[] iso=new boolean[s.length];
		for(int i=0; i<s.length; i++){
			iso[i]=isIsomorphic(s[i], t[i]);
			if(iso[i]) System.out.println("'"+s[i]+"' and '"+t[i]+"' are isomorphic");
			else System.out.println("'"+s[i]+"' and '"+t[i]+"' aren't isomorphic");
		}
	}
}