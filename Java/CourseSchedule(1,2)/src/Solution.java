import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.stream.IntStream;

public class Solution {
	//Course Schedule I, determine if can finish the course
	public static boolean canFinish(int numCourses, int[][] prerequisites){
		int len=prerequisites.length;
		if(numCourses==0 || len==0) return true;
		
		//Count number of prerequisites for different courses
		int[] numPres=new int[numCourses];
		for(int i=0; i<len; i++)
			numPres[prerequisites[i][0]]++;
		
		//Store courses with no prerequisites in a queue
		Queue<Integer> courseNoPres=new ArrayDeque<Integer>(numCourses);
		for(int i=0; i<numCourses; i++){
			if(numPres[i]==0) courseNoPres.add(i);
		}
		
		//Initialize number of courses with no prerequisites
		int noOfCourses=courseNoPres.size();
		
		while(!courseNoPres.isEmpty()){
			int top=courseNoPres.poll();
			for(int i=0; i<len; i++){
				if(prerequisites[i][1]==top){
					numPres[prerequisites[i][0]]--;
					if(numPres[prerequisites[i][0]]==0){
						noOfCourses++;
						courseNoPres.add(prerequisites[i][0]);
					}
				}
			}
		}
		
		return numCourses==noOfCourses;
	}
	
	//Course Schedule II, return the order to finish all courses
	public static int[] findOrder(int numCourses, int[][] prerequisites){
		int len=prerequisites.length;
		if(len==0){
			int[] result=new int[numCourses];
			for(int i=0; i<numCourses; i++)
				result[i]=i;
			return result;
		}
		
		int[] noPres=new int[numCourses];
		for(int i=0; i<len; i++)
			noPres[prerequisites[i][0]]++;
		
		Queue<Integer> courseNoPres=new ArrayDeque<Integer>(numCourses);
		for(int i=0; i<numCourses; i++){
			if(noPres[i]==0) courseNoPres.add(i);
		}
		
		int noCoursesNoPres=courseNoPres.size();
		int[] result=new int[numCourses];
		int j=0;
		
		while(j<numCourses && !courseNoPres.isEmpty()){
			int top=courseNoPres.poll();
			result[j++]=top;
			for(int i=0; i<len; i++){
				if(prerequisites[i][1]==top){
					noPres[prerequisites[i][0]]--;
					if(noPres[prerequisites[i][0]]==0){
						noCoursesNoPres++;
						courseNoPres.add(prerequisites[i][0]);
					}
				}
			}
		}
		if(noCoursesNoPres==numCourses)
			return result;
		else{
			int[] res=new int[0];
			return res;
		}
	}
	
	//Main
	public static void main(String[] args){
		int numCourses=4;
		//int[][] prerequisites={{1,0}};
		int[][] prerequisites={{1,0},{2,0},{3,1},{2,1},{3,0}};
		if(canFinish(numCourses, prerequisites))
		{
			System.out.println("Can finish all courses");
			System.out.println("The course taken order is: "+Arrays.toString(findOrder(numCourses, prerequisites)));
		}
		else 
			System.out.println("Can't finish all courses");
		
	}
}
