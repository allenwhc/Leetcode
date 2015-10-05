import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class PeekingIterator implements Iterator<Integer> {
	private static Iterator<Integer> x;
	private static Integer y;
 	public PeekingIterator(Iterator<Integer> iterator){
		x=iterator;
		y=null;
	}

	public boolean hasNext() {
		if(y!=null) return true;
		return x.hasNext();
	}

	public Integer next() {
		Integer z=null;
		if(y==null){
			y=x.next();
			z=y;
			y=null;
			return z;
		}
		z=y;
		y=null;
		return z;
	}
	
	// Returns the next element in the iteration without advancing the iterator.
	public static Integer peek() {
		if(y==null)
			y=x.next();
	    return y;
	}
	public static void main(String[] args) {
		List<Integer> list=new ArrayList<>();
		list.add(1);
		list.add(2);
		list.add(3);
		Iterator<Integer> iterator=list.iterator();
		PeekingIterator p=new PeekingIterator(iterator);
		System.out.println("Next element: "+p.next());
		System.out.println("Peek element: "+p.peek());
		System.out.println("Next element: "+p.next());
		System.out.println("Next element: "+p.next());
	}
}