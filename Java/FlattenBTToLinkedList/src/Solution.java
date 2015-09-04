
public class Solution {
	public static class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		public TreeNode(int x) {
			val=x;
		}
		
		public static TreeNode newNode(int val){
			TreeNode node=new TreeNode(val);
			node.left=null;
			node.right=null;
			return node;
		}
		
		public static void printBinaryTree(TreeNode root, int level){
		    if(root==null)
		         return;
		    printBinaryTree(root.right, level+1);
		    if(level!=0){
		        for(int i=0;i<level-1;i++)
		            System.out.print("|\t");
		            System.out.println("|-------"+root.val);
		    }
		    else
		        System.out.println(root.val);
		    printBinaryTree(root.left, level+1);
		}   
	}
	
	public static void flatten(TreeNode root){
		convert(root, new TreeNode[1]);
	}
	
	private static void convert(TreeNode node, TreeNode[] prev){
		if(node==null) return;
		TreeNode right=node.right;
		if(prev[0]!=null)
			prev[0].right=node;
		prev[0]=node;
		convert(node.left, prev);
		node.left=null;
		convert(right, prev);
	}
	
	public static void main(String[] args) {
		TreeNode root=new TreeNode(1);
		root.left=new TreeNode(2);
		root.left.left=new TreeNode(3);
		root.left.right=new TreeNode(4);
		root.right=new TreeNode(5);
		root.right.right=new TreeNode(6);
		System.out.println("The original binary tree is: ");
		TreeNode.printBinaryTree(root, 0);
		System.out.println("The flattened binary tree is: ");
		flatten(root);
		TreeNode.printBinaryTree(root, 0);
	}
}