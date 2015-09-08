
import java.util.ArrayList;
import java.util.List;

public class Solution {
	public static String simplifyPath(String path){
		List<String> stack=new ArrayList<>();
		int n=path.length();
		if(n==0) return "";
		int i=0;
		String str=new String();
		while(i<n){
			while(i<n && path.charAt(i)=='/' ) i++;
			if(i==n) break;
			int start=i;
			while(i<n && path.charAt(i)!='/' ) i++;
			int end=i;
			str=path.substring(start, end);
			if(str.equals("..")){
				if(!stack.isEmpty())
					stack.remove(stack.size()-1);
			}
			else if(!str.equals("."))
				stack.add(str);
		}
		if(stack.isEmpty())
			return "/";
		StringBuffer result=new StringBuffer();
		for(int j=0; j<stack.size(); j++)
			result.append("/").append(stack.get(j));
		return result.toString();
	}
	
	public static void main(String[] args) {
		String[] paths={"/home//..//file///leetcode/","/a/./b/../../c/","/home/foo/.ssh/../.ssh2/authorized_keys/"};
		for(int i=0; i<paths.length; i++)
			System.out.println("The simplified path of '"+paths[i]+"' is: "+simplifyPath(paths[i]));
	}
}
