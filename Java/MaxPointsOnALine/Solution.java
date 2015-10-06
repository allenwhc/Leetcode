import java.util.HashMap;

public class Solution{
	public static class Point{
		int x;
		int y;
		Point(){x=0;y=0;}
		Point(int a, int b){x=a;y=b;}
	}

	public static int maxPoints(Point[] points){
		if(points.length==0) return 0;
		HashMap<Double,Integer> map=new HashMap<Double,Integer>();
		int maxNum=Integer.MIN_VALUE;
		for(int i=0; i<points.length; i++){
			map.clear();	//Clear hash map at beginning of each iteration
			map.put((double)Integer.MIN_VALUE,0);
			int duplicate=1;
			for(int j=0; j<points.length; j++){
				if(j==i) continue;
				//Check if two points are the same
				if(points[i].x==points[j].x && points[i].y==points[j].y){
					duplicate++;
					continue;
				}
				//If two points are on the same vertical line, set slope to be infinite
				//Else, compute slope between two points
				double slope=(points[i].x==points[j].x)?Integer.MAX_VALUE:((double)points[j].y-(double)points[i].y)/((double)points[j].x-(double)points[i].x);
				if(map.containsKey(slope))
					map.put(slope,map.get(slope)+1);
				else
					map.put(slope,1);
			}

			//Update max points for each point in the points set
			for(double d:map.keySet()){
				maxNum=Math.max(maxNum,duplicate+map.get(d));
			}
		}
		return maxNum;
	}

	public static void main(String[] args){
		Point p1=new Point(1,1);
		Point p2=new Point(1,3);
		Point p3=new Point(2,2);
		Point p4=new Point(6,2);
		Point p5=new Point(3,3);
		Point p6=new Point(7,7);

		Point[] points={p1,p2,p3,p4,p5,p6};
		System.out.println("Max points on a line is: "+maxPoints(points));
	}
}