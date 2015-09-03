
public class Solution {
	public static class TreeNode{
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
	
	public static TreeNode upsideDownBinaryTree(TreeNode root) {
        if(root==null) return null;
        if(root.left==null && root.right==null)
        	return root;
        TreeNode node=upsideDownBinaryTree(root.left);
        root.left.left=root.right;
        root.left.right=root;
        root.left=root.right=null;
        return node;
    }
	
	public static void main(String[] args){
		TreeNode root=new TreeNode(1);
		root.left=new TreeNode(2);
		root.right=new TreeNode(3);
		root.left.left=new TreeNode(4);
		root.left.right=new TreeNode(5);
		System.out.println("The original binary tree is:");
		TreeNode.printBinaryTree(root, 0);
		System.out.println("The upside-down binary tree is:");
		TreeNode.printBinaryTree(upsideDownBinaryTree(root), 0);
	}
}