
import java.util.LinkedList;

public class Solution {
	static LinkedList<Integer> queue1 = new LinkedList<Integer>();
	static    LinkedList<Integer> queue2 = new LinkedList<Integer>();
	 
	    // Push element x onto stack.
	    public static void push(int x) {
	        if(empty()){
	            queue1.offer(x);
	        }else{
	            if(queue1.size()>0){
	                queue2.offer(x);
	                int size = queue1.size();
	                while(size>0){
	                    queue2.offer(queue1.poll());
	                    size--;
	                }
	            }else if(queue2.size()>0){
	                queue1.offer(x);
	                int size = queue2.size();
	                while(size>0){
	                    queue1.offer(queue2.poll());
	                    size--;
	                }
	            }
	        }
	    }
	 
	    // Removes the element on top of the stack.
	    public static void pop() {
	        if(queue1.size()>0){
	            queue1.poll();
	        }else if(queue2.size()>0){
	            queue2.poll();
	        }
	    }
	 
	    // Get the top element.
	    public static int top() {
	       if(queue1.size()>0){
	            return queue1.peek();
	        }else if(queue2.size()>0){
	            return queue2.peek();
	        }
	        return 0;
	    }
	 
	    // Return whether the stack is empty.
	    public static boolean empty() {
	        return queue1.isEmpty() & queue2.isEmpty();
	    }
	
	public static void main(String[] args){
		push(1);
		//push(2);
		//System.out.println(empty());
		System.out.println("Top of stack: "+top());
		pop();
		System.out.println("Empty Stack? "+empty());
	}
}
