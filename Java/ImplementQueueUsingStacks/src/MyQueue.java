import java.util.Stack;

public class MyQueue {
	private static Stack<Integer> stack1=new Stack<>();
	private static Stack<Integer> stack2=new Stack<>();
	
	// Push element x to the back of queue.
    public static void push(int x) {
        stack1.push(x);
    }

    // Removes the element from in front of queue.
    public static void pop() {
        while(stack1.size()>1)
        	stack2.push(stack1.pop());
        stack1.pop();
        while(!stack2.isEmpty())
        	stack1.push(stack2.pop());
    }

    // Get the front element.
    public static int peek() {
        while(stack1.size()>1)
        	stack2.push(stack1.pop());
        int top=stack1.peek();
        while(!stack2.isEmpty())
        	stack1.push(stack2.pop());
        return top;
    }

    // Return whether the queue is empty.
    public static boolean empty() {
        return stack1.isEmpty();
    }
    
    public static void main(String[] args){
    	push(1);
    	pop();
    	System.out.println(empty());
    }
}
