import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class Vector2D {
	private static Iterator<List<Integer>> x;
	private static Iterator<Integer> y;
	public Vector2D(List<List<Integer>> vec2d){
		x=vec2d.iterator();
	}
	
	public static int next(){
		hasNext();
		return y.next();
	}
	
	public static boolean hasNext(){
		while((y==null || !y.hasNext()) && x.hasNext())
			y=x.next().iterator();
		return y!=null && y.hasNext();
	}
	
	public static void main(String[] args) {
		Integer[][] arr2d={{},{7,2},{3},{4,5,6}};
		List<List<Integer>> vec2d=new ArrayList<List<Integer>>();
		for(int i=0; i<arr2d.length; i++)
			vec2d.add(Arrays.asList(arr2d[i]));
		System.out.println("The 2D vector is: ");
		for(List<Integer> l:vec2d)
			System.out.println(Arrays.deepToString(l.toArray()));
		List<Integer> vec1d=new ArrayList<>();
		Vector2D i=new Vector2D(vec2d);
		while(i.hasNext())
			vec1d.add(i.next());
		System.out.print("The flattened 1D vector is: ");
		System.out.println(Arrays.deepToString(vec1d.toArray()));
	}
}