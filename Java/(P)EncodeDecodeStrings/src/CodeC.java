import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CodeC {
	// Encodes a list of strings to a single string.
    public static String encode(List<String> strs) {
        StringBuffer code=new StringBuffer();
        for(int i=0; i<strs.size(); i++)
        	code.append(strs.get(i).length()).append("/").append(strs.get(i));
        return code.toString();
    }

    // Decodes a single string to a list of strings.
    public static List<String> decode(String s) {
        List<String> decode=new ArrayList<>();
        int i=0;
        while(i<s.length()){
        	int slashIndex=s.indexOf('/', i);	//Get index of '/'  in current segment
        	int size=Integer.valueOf(s.substring(i, slashIndex));
        	decode.add(s.substring(slashIndex+1, slashIndex+1+size));
        	i=slashIndex+size+1;
        }
        return decode;
    }
    
    public static void main(String[] args) {
		List<String> strs=new ArrayList<>();
		String[] strings={"My","e-mail","address","is",":","abc1^2%3^@gmail.com."};
		for(String s:strings)
			strs.add(s);
		System.out.println("The input message is: "+Arrays.deepToString(strs.toArray()));
		CodeC code=new CodeC();
		System.out.println("The encoded message is: "+encode(strs));
		System.out.println("The decoded message is: "+Arrays.deepToString(code.decode(encode(strs)).toArray()));
	}
}
