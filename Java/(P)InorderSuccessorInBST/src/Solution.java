
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
	
	public static TreeNode inorderSuccessor(TreeNode root, TreeNode p){
		if(root==null) return null;
		if(p.right!=null)
			return leftMostNode(p.right);
		TreeNode successor=null;
		while(root!=null){
			if(p.val>root.val)
				root=root.right;
			else if(p.val<root.val){
				successor=root;
				root=root.left;
			}
			else break;
		}
		return successor;
	}
	
	private static TreeNode leftMostNode(TreeNode node){
		TreeNode curr=node;
		while(curr.left!=null)
			curr=curr.left;
		return curr;
	}
	
	public static void main(String[] args) {
		TreeNode root=new TreeNode(7);
		root.left=new TreeNode(3);
		root.right=new TreeNode(11);
		root.left.left=new TreeNode(1);
		root.left.right=new TreeNode(5);
		root.right.left=new TreeNode(9);
		root.right.right=new TreeNode(13);
		System.out.println("The BST is: ");
		TreeNode.printBinaryTree(root, 0);
		
		TreeNode p=root.left.right;
		System.out.println("The inorder successor of "+p.val+" is "+inorderSuccessor(root, p).val);
	}
}
