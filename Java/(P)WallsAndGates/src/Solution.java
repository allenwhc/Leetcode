import java.util.Arrays;

public class Solution {
	public static void wallsAndGates(int[][] rooms) {
        if(rooms.length==0) return;
        if(rooms[0].length==0) return;
        for(int i=0; i<rooms.length; i++){
        	for(int j=0; j<rooms[0].length; j++){
        		if(rooms[i][j]==0){
        			filledRoom(rooms, i+1, j, rooms[i][j]+1);
        			filledRoom(rooms, i-1, j, rooms[i][j]+1);
        			filledRoom(rooms, i, j+1, rooms[i][j]+1);
        			filledRoom(rooms, i, j-1, rooms[i][j]+1);
        		}
        	}
        }
    }
	
	private static void filledRoom(int[][] rooms, int i, int j, int distance){
		int m=rooms.length;
		int n=rooms[0].length;
		if(i<0 || j<0 || i>=m || j>=n) return;
		if(rooms[i][j]==-1) return;
		if(distance<rooms[i][j])
			rooms[i][j]=distance;
		else
			return;
		filledRoom(rooms, i+1, j, rooms[i][j]+1);
		filledRoom(rooms, i-1, j, rooms[i][j]+1);
		filledRoom(rooms, i, j+1, rooms[i][j]+1);
		filledRoom(rooms, i, j-1, rooms[i][j]+1);
	}
	
	public static void main(String[] args) {
		int INF=Integer.MAX_VALUE;
		int[][] rooms={{INF,-1,0,INF},
						{INF,INF, INF,-1},
						{INF,-1,INF,-1},
						{0,-1,INF,INF}};
		System.out.println("The room's original distribution is: ");
		for(int [] l:rooms)
			System.out.println(Arrays.toString(l));
		wallsAndGates(rooms);
		System.out.println();
		System.out.println("The room's filled distributio is: ");
		for(int [] l:rooms)
			System.out.println(Arrays.toString(l));
	}
}
