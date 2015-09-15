import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class ZigzagIterator {
	private static Iterator<Integer> l1, l2, tmp;
    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        l1=v1.iterator();
        l2=v2.iterator();
    }

    public int next() {
        if(l1.hasNext()){
        	tmp=l1;
        	l1=l2;
        	l2=tmp;
        }
        return l2.next();
    }

    public boolean hasNext() {
        return l1.hasNext() || l2.hasNext();
    }
    
    public static void main(String[] args) {
        List<Integer> v1=new ArrayList<>();
        List<Integer> v2=new ArrayList<>();
        int[] arr1={1,2};
        int[] arr2={3,4,5,6};
        for(int i:arr1)
        	v1.add(i);
        for(int i:arr2)
        	v2.add(i);
        ZigzagIterator z=new ZigzagIterator(v1, v2);
        List<Integer> v=new ArrayList<>();
        while(z.hasNext())
        	v.add(z.next());
        System.out.println("The zigzag list is: "+Arrays.deepToString(v.toArray()));
	}
}