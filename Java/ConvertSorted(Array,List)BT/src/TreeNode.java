

public class TreeNode {
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
