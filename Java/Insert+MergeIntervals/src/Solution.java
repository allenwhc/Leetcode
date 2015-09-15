import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Solution {
	public static class Interval{
		int start;
		int end;
		Interval(){start=end=0;}
		Interval(int s, int e){start=s;end=e;}
	}
	
	//Insert Interval
	public static List<Interval> insert(List<Interval> intervals, Interval newInterval){
		List<Interval> result=new ArrayList<>();
		int n=intervals.size();
		if(n==0){
			result.add(newInterval);
			return result;
		}
		int i=0;
		while(i<n && intervals.get(i).end<newInterval.start)
			result.add(intervals.get(i++));
		
		//Interval ii=new Interval(intervals.get(i).start,intervals.get(i).end);
		while(i<n && intervals.get(i).start<=newInterval.end){
			newInterval.start=Math.min(intervals.get(i).start, newInterval.start);
			newInterval.end=Math.max(intervals.get(i).end, newInterval.end);
			i++;
		}
		result.add(newInterval);
		while(i<n)
			result.add(intervals.get(i++));
		return result;
	}
	
	//Merge Interval
	public static List<Interval> merge(List<Interval> intervals){
		List<Interval> result=new ArrayList<Interval>();
		int n=intervals.size();
		if(n==0) return result;
		
		//Firstly, sort list by start
		Collections.sort(intervals,new Comparator<Interval>() {
			public int compare(Interval o1, Interval o2){
				Integer x1=o1.start;
				Integer x2=o2.start;
				return x1.compareTo(x2);
			}
		});

		result.add(intervals.get(0));
		for(int i=1; i<n; i++){
			if(intervals.get(i).start<=result.get(result.size()-1).end){
				Interval inte=new Interval();
				inte.start=result.get(result.size()-1).start;
				inte.end=Math.max(intervals.get(i).end, result.get(result.size()-1).end);
				result.remove(result.size()-1);
				result.add(inte);
			}
			else
				result.add(intervals.get(i));
		}
		
		return result;
	}
	
	public static void main(String[] args) {
		List<Interval> intervals=new ArrayList<Interval>();
		int[][] setIntervals={{1,2},{3,5},{6,7},{8,10},{12,16}};
		System.out.println("Insert Interval: ");
		for(int i=0; i<setIntervals.length; i++){
			Interval intv=new Interval(setIntervals[i][0], setIntervals[i][1]);
			intervals.add(intv);
		}
		
		Interval newInterval=new Interval(4, 9);
		System.out.print("The original non-overlapping intervals is: ");
		for(Interval i:intervals){
			System.out.print("("+i.start+","+i.end+"), ");
		}
		System.out.println();
		System.out.println("The inserting new interval is: ("+newInterval.start+","+newInterval.end+").");
		System.out.print("The inserted intervals is: ");
		for(Interval i:insert(intervals, newInterval)){
			System.out.print("("+i.start+","+i.end+"), ");
		}
		System.out.println();
		System.out.println();
		System.out.println("Merge Intervals: ");
		intervals.clear();
		int[][] setIntervals2={{2,3},{4,5},{6,7},{8,9},{1,10}};
		for(int i=0; i<setIntervals2.length; i++){
			Interval intv=new Interval(setIntervals2[i][0], setIntervals2[i][1]);
			intervals.add(intv);
		}
		System.out.print("The original overlapping intervals is: ");
		for(Interval i:intervals){
			System.out.print("("+i.start+","+i.end+"), ");
		}
		System.out.println();
		System.out.print("The merged intervals is: ");
		for(Interval i:merge(intervals)){
			System.out.print("("+i.start+","+i.end+"), ");
		}
		System.out.println();
	}
}