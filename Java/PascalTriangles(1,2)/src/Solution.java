import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import javax.xml.ws.ResponseWrapper;

public class Solution {
	//Pascal Triangle I, return all rows
	public static List<List<Integer>> generate(int numRows) {
		List<List<Integer>> triangle=new ArrayList<List<Integer>>();
		if(numRows<=0) return triangle;
		List<Integer> lastRow=new ArrayList<Integer>();
		lastRow.add(1);
		for(int i=1; i<=numRows; i++){
			List<Integer> currRow=new ArrayList<Integer>();
			currRow.add(lastRow.get(0));
			for(int j=1; j<i; j++){	
				currRow.add(lastRow.get(j-1)+lastRow.get(j));
			}
			currRow.add(lastRow.get(0));
			triangle.add(new ArrayList<Integer>(lastRow));
			lastRow=currRow;
		}
		return triangle;
	}
	
	//Pascal Triangle II, return kth row
	public static List<Integer> getRow(int rowIndex) {
		List<Integer> row=new ArrayList<Integer>();
		row.add(1);
		for(int i=1; i<=rowIndex; i++){
			for(int j=row.size()-2; j>=0; j--)
				row.set(j+1, row.get(j)+row.get(j+1));
			row.add(1);
		}
		return row;
	}
	
	//Main
	public static void main(String[] args) {
		int numRows=5;
		int rowIndex=4;
		System.out.println("A "+numRows+"-row Pascal Triangle is");
		List<List<Integer>> triangle=generate(numRows);
		for(List<Integer> rows:triangle)
			System.out.println(Arrays.deepToString(rows.toArray()));
		System.out.print("The "+rowIndex+"th row in Pascal Triangle is: "+Arrays.deepToString(getRow(rowIndex).toArray()));
		
	}
}
