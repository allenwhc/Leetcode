
public class Reader4 {
	public static int read4(char[] buff){
		
	}
	
	public static class Solution extends Reader4{
		/**
	     * @param buf Destination buffer
	     * @param n   Maximum number of characters to read
	     * @return    The number of characters read
	     */
	    public static int read(char[] buf, int n) {
	        char[] buffer=new char[4];
	        int idx=0;
	        while(true){
	        	int curr=read4(buffer);
	        	int curr_len=Math.min(curr, n-idx);
	        	for(int i=0; i<curr_len; i++)
	        		buf[idx+i]=buffer[i];
	        	idx+=curr_len;
	        	if(idx==n || curr_len!=4) return idx;
	        }
	    }
	}
	
	public static void main(String[] args) {
		String str="28cboqwr8^&%)()sadfakfb";
		char[] buff=str.toCharArray();
		
	}
}
