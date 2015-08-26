import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	//Preorder traversal
	public static List<Integer> preorderTraversal(TreeNode root){
		List<Integer> preorderResult=new ArrayList<Integer>();
		traversePreorder(root, preorderResult);
		return preorderResult;
	}
	
	public static void traversePreorder(TreeNode root, List<Integer> values){
		if(root==null) return;
		values.add(root.val);
		traversePreorder(root.left, values);
		traversePreorder(root.right, values);
	}
	
	//Inorder traversal
		public static List<Integer> inorderTraversal(TreeNode root){
			List<Integer> inorderResult=new ArrayList<Integer>();
			traverseInorder(root, inorderResult);
			return inorderResult;
		}
		
		public static void traverseInorder(TreeNode root, List<Integer> values){
			if(root==null) return;
			traverseInorder(root.left, values);
			values.add(root.val);
			traverseInorder(root.right, values);
		}
		
		//Postorder traversal
		public static List<Integer> postorderTraversal(TreeNode root){
			List<Integer> postorderResult=new ArrayList<Integer>();
			traversePostorder(root, postorderResult);
			return postorderResult;
		}
				
		public static void traversePostorder(TreeNode root, List<Integer> values){
			if(root==null) return;
			traversePostorder(root.left, values);
			traversePostorder(root.right, values);
			values.add(root.val);
		}
	
		//Levelorder traversal (top-down)
		public static List<List<Integer>> levelOrder(TreeNode root){
			List<List<Integer>> allLevels=new ArrayList<List<Integer>>();
			List<Integer> level=new ArrayList<Integer>();
			if(root==null) return allLevels;
			int h=treeHeight(root);
			for(int i=1; i<=h; i++){
				List<Integer> temp= new ArrayList<Integer>(traverseLevelOrder(root, i, level));
				allLevels.add(temp);
				level.clear();
			}
			return allLevels;
		}
		
		//Levelorder traversal (bottom-up)
		public static List<List<Integer>> levelOrderBottom(TreeNode root){
			List<List<Integer>> allLevels=new ArrayList<List<Integer>>();
			List<Integer> level=new ArrayList<Integer>();
			if(root==null) return allLevels;
			int h=treeHeight(root);
			for(int i=h; i>=1; i--){
				List<Integer> temp= new ArrayList<Integer>(traverseLevelOrder(root, i, level));
				allLevels.add(temp);
				level.clear();
			}
			return allLevels;
		}
		
		private static List<Integer> traverseLevelOrder(TreeNode node, int step, List<Integer> level){
			if(node==null) return level;
			if(step==1){
				level.add(node.val);
				return level;
			}
			else{
				level=traverseLevelOrder(node.left, step-1, level);
				level=traverseLevelOrder(node.right, step-1, level);
				return level;
			}
		}
		
		//Calculate the height of the given tree
		private static int treeHeight(TreeNode node){
			if(node==null) return 0;
			int lh=treeHeight(node.left);
			int rh=treeHeight(node.right);
			return Math.max(lh, rh)+1;
		}
		
		//Main
		public static void main(String[] args) {
			TreeNode root=null;
			root=TreeNode.newNode(1);
			root.left=TreeNode.newNode(2);
			root.right=TreeNode.newNode(3);
			root.left.left=TreeNode.newNode(4);
			root.left.right=TreeNode.newNode(5);
			root.right.right=TreeNode.newNode(6);
			System.out.println("The binary is: ");
			TreeNode.printBinaryTree(root, 0);
			System.out.println("The preorder traversal is:"+Arrays.deepToString(preorderTraversal(root).toArray()));
			System.out.println("The inorder traversal is:"+Arrays.deepToString(inorderTraversal(root).toArray()));
			System.out.println("The postorder traversal is:"+Arrays.deepToString(postorderTraversal(root).toArray()));
			System.out.println("The top-down level order traversal is: ");
			for(List<Integer> ls:levelOrder(root))
				System.out.println(Arrays.deepToString(ls.toArray()));
			System.out.println("The bottom-up level order traversal is: ");
			for(List<Integer> ls:levelOrderBottom(root))
				System.out.println(Arrays.deepToString(ls.toArray()));
		}
	
}
