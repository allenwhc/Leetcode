
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
	
	public static int sumNumbers(TreeNode root){
		if(root==null) return 0;
		int[] sum=new int[1];
		getSum(root, 0, sum);
		return sum[0];
	}
	
	private static void getSum(TreeNode node, int level, int[] sum){
		if(node==null) return;
		if(node.left==null && node.right==null){
			level=level*10+node.val;
			sum[0]+=level;
			return;
		}
		level=level*10+node.val;
		getSum(node.left, level, sum);
		getSum(node.right, level, sum);
	}
	
	public static void main(String[] args){
		TreeNode root=new TreeNode(1);
		root.left=new TreeNode(2);
		root.right=new TreeNode(3);
		root.left.left=new TreeNode(4);
		root.left.right=new TreeNode(5);
		System.out.println("The original binary tree is:");
		TreeNode.printBinaryTree(root, 0);
		System.out.println("Sum to leaf sum is: "+sumNumbers(root));
	}

}