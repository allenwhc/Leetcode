import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	//Path Sum I, check if a root-to-leaf path has a given sum exists
	public static boolean hasPathSum(TreeNode root, int sum){
		return checkSum(root, 0, sum);
	}
	
	private static boolean checkSum(TreeNode node, int curSum, int sum){
		if(node==null) return false;
		curSum+=node.val;
		if(node.left==null && node.right==null && curSum==sum) 
			return true;
		return checkSum(node.left, curSum, sum) || checkSum(node.right, curSum, sum);
	}
	
	//Path Sum II, return all paths having the given sum
	public static List<List<Integer>> pathSum2(TreeNode root, int sum){
		List<List<Integer>> allPaths=new ArrayList<List<Integer>>();
		List<Integer> path=new ArrayList<Integer>();
		if(root==null) return allPaths;
		path.add(root.val);
		generatePath(root, allPaths, path, sum-root.val);
		return allPaths;
	}
	
	private static void generatePath(TreeNode root, List<List<Integer>> allPaths, List<Integer> path, int leftSum){
		if(root==null) return;
		if(root.left==null && root.right==null && leftSum==0){
			List<Integer> temp=new ArrayList<Integer>(path);
			allPaths.add(temp);
		}
		if(root.left!=null){
			path.add(root.left.val);
			generatePath(root.left, allPaths, path, leftSum-root.left.val);
			path.remove(path.size()-1);
		}
		if(root.right!=null){
			path.add(root.right.val);
			generatePath(root.right, allPaths, path, leftSum-root.right.val);
			path.remove(path.size()-1);
		}
	}
	
	//Main
	public static void main(String[] args) {
		TreeNode root=null;
		root=TreeNode.newNode(5);
		root.left=TreeNode.newNode(4);
		root.right=TreeNode.newNode(8);
		root.left.left=TreeNode.newNode(11);
		root.right.left=TreeNode.newNode(13);
		root.right.right=TreeNode.newNode(4);
		root.left.left.left=TreeNode.newNode(7);
		root.left.left.right=TreeNode.newNode(2);
		root.right.right.right=TreeNode.newNode(1);
		root.right.right.left=TreeNode.newNode(5);
		
		System.out.println("The binary tree is:");
		TreeNode.printBinaryTree(root, 0);
		int sum=22;
		if(hasPathSum(root, sum)){
			System.out.println("The tree has a path whose sum is "+sum);
			System.out.println("The paths are: ");
			for(List<Integer> ls:pathSum2(root, sum))
				System.out.println(Arrays.deepToString(ls.toArray()));
		}
		else System.out.println("The tree doesn't have a path whose sum is "+sum);
	}
}
