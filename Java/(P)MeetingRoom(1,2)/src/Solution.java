import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {
	//Meeting Rooms I
	public static boolean canAttendMeetings(Interval[] intervals){
		int n=intervals.length;
		if(n<=1) return true;
		sort(intervals);
		for(int i=1; i<n; i++){
			if(intervals[i].start<intervals[i-1].end) return false;
		}
		return true;
	}

	//Meeting Rooms II
	public static int minMeetingRooms(Interval[] intervals){
		int n=intervals.length;
		if(n==0) return 0;
		sort(intervals);
		
		//Set up a priority queue
		PriorityQueue<Interval> q=new PriorityQueue<>(intervals.length, new Comparator<Interval>() {
			public int compare(Interval o1, Interval o2){
				Integer x1=o1.end;
				Integer x2=o2.end;
				return x1.compareTo(x2);
			}
		});
		
		for(int i=0;i<n; i++){
			if(q.isEmpty())
				q.offer(intervals[i]);
			else{
				Interval prev_meeting=q.poll();
				//If current meeting starts before previous meeting was over, add current meeting to the queue
				if(intervals[i].start<prev_meeting.end)
					q.offer(intervals[i]);
				else
					prev_meeting.end=intervals[i].end;	//Change end time to current meeting's end time
				q.offer(prev_meeting);	//Add the previous meeting back
			}
		}
		return q.size();
	}
	
	//Sort by starting time
	private static void sort(Interval[] intervals){
		Arrays.sort(intervals, new Comparator<Interval>() {
			public int compare(Interval o1, Interval o2){
				Integer x1=o1.start;
				Integer x2=o2.start;
				return x1.compareTo(x2);
			}
		});
	}
	
	public static void main(String[] args){
		Interval i1=new Interval();
		Interval i2=new Interval();
		Interval i3=new Interval();
		i1.start=9;
		i1.end=10;
		i2.start=4;
		i2.end=9;
		i3.start=4;
		i3.end=17;
		Interval[] intervals={i1,i2,i3};
		System.out.println("The meeting schedule is: ");
		for(int i=0; i<intervals.length; i++)
			System.out.println("Meeting "+(i+1)+", "+"starts at: "+intervals[i].start+", ends at: "+intervals[i].end+";");
		if(canAttendMeetings(intervals))
			System.out.println("All meetings can be attended.");
		else
			System.out.println("Not all meetings can be attended.");
		System.out.println("Minimum meeting rooms needed: "+minMeetingRooms(intervals));
	}
}
