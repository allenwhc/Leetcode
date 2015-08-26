import java.util.ArrayList;
import java.util.List;

public class Solution {
	//Unique BST I
	public static int numTrees(int n){
		if(n<=1) return 1;
		int[] countTrees=new int[n+1];
		countTrees[0]=countTrees[1]=1;
		for(int i=2; i<=n; i++){
			for(int j=0; j<i; j++)
				countTrees[i]+=countTrees[i-j-1]*countTrees[j];
		}
		return countTrees[n];
	}
	
	//Unique BST II
	public static List<TreeNode> generateTrees(int n) {
		return create(1, n);
	}
	
	private static List<TreeNode> create(int start, int end){
		List<TreeNode> result=new ArrayList<TreeNode>();
		if(start>end){
			result.add(null);
			return result;
		}
		
		for(int i=start; i<=end; i++){
			List<TreeNode> leftSubTree=create(start, i-1);
			List<TreeNode> rightSubTree=create(i+1, end);
			for(TreeNode l:leftSubTree){
				for(TreeNode r:rightSubTree){
					TreeNode node=new TreeNode(i);
					node.left=l;
					node.right=r;
					result.add(node);
				}
			}
		}
		return result;
	}
	
	public static void main(String[] args){
		int n=3;
		System.out.println("There are "+numTrees(n)+" unique BSTs to store 1 to "+n);
		System.out.println("All unique BSTs are:");
		
		for(TreeNode node:generateTrees(n))
			TreeNode.printBinaryTree(node, 0);
	}
}
