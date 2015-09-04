import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class Solution {
	//H-Index I
	public static int hIndex(int[] citations){
		int n=citations.length;
		if(n==0) return 0;
		
		//Sort array in descending order
		Arrays.sort(citations);

		//Map (citations[i], i+1) to HashTable
		HashMap<Integer, Integer> map=new HashMap<>();
		map.put(citations[0], n);
		for(int i=1; i<n; i++){
			if(citations[i]==citations[i-1]) continue;
			map.put(citations[i], n-i);
		}
		
		//Find the last index where citations[index]>=index
		int index=0;
		for(Integer key:map.keySet()){
			index=Math.max(index, Math.min(key, map.get(key)));
		}
		
		return index;
	}
	
	//H-Index II
	public static int hIndex2(int[] citations) {
        int n=citations.length;
        if(n==0) return 0;
        
        int l=0, r=n-1;
        while(l<r){
        	int m=(l+r)/2;
        	if(citations[m]<n-m) l=m+1;
        	else r=m;
        }
        return citations[r]==0?0:n-r;
    }
	
	public static void main(String[] args){
		int[] citations={100};
		System.out.println("The citations are: "+Arrays.toString(citations));
		System.out.println("The maximum H-Index is: "+hIndex(citations));
		int[] sorted_citations=citations;
		Arrays.sort(sorted_citations);
		System.out.println("The sorted citations are: "+Arrays.toString(sorted_citations));
		System.out.println("The maximum H-Index is: "+hIndex2(sorted_citations));
	}
}