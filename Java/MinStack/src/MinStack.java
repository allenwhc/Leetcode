import java.util.Stack;

public class MinStack {
	private static Stack<Integer> acutalStack=new Stack<>();
	private static Stack<Integer> minStack=new Stack<>();
	
	public static void push(int x) {
        acutalStack.push(x);
        if(x<=getMin())
        	minStack.push(x);
    }

    public static void pop() {
        if(acutalStack.peek()==getMin()) minStack.pop();
        acutalStack.pop();
    }

    public static int top() {
        return acutalStack.peek();
    }

    public static int getMin() {
        if(minStack.isEmpty()) return Integer.MAX_VALUE;
        return  minStack.peek();
    }
    
    public static void main(String[] args){
    	push(-1);
    	System.out.println("Top element: "+top());
    	System.out.println("Minimum value: "+getMin());
    }
}
