
public class Solution {
	private static int count=0;
	public static int countUnivalSubtrees(TreeNode root){
		if(root==null) return 0;
		isUnivalSubtree(root);
		return count;
	}
	
	private static boolean isUnivalSubtree(TreeNode root){
		if(root==null) return true;
		boolean leftUnivalSubtree=isUnivalSubtree(root.left);
		boolean rightUnivalSubtree=isUnivalSubtree(root.right);
		if(leftUnivalSubtree && 
			rightUnivalSubtree &&
			(root.left==null || root.val==root.left.val) &&
			(root.right==null || root.val==root.right.val)){
			count++;
			return true;
		}
		return false;
	}
	
	
	public static void main(String[] args){
		TreeNode root=new TreeNode(5);
		root.left=new TreeNode(1);
		root.right=new TreeNode(5);
		root.left.left=new TreeNode(5);
		root.left.right=new TreeNode(5);
		root.right.right=new TreeNode(5);
		System.out.println("The binary tree is:");
		TreeNode.printBinaryTree(root, 0);
		System.out.println("Number of univalue subtrees: "+countUnivalSubtrees(root));
	}
}