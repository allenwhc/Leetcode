import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

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
	
	//Closest BST value I
	public static int closestValue(TreeNode root, double target){
		if(root==null) return 0;
		double diff=Integer.MAX_VALUE;
		int[] closestNodeValue=new int[1];
		closestNodeValue[0]=Integer.MAX_VALUE;
		findClosest(root, target, diff, closestNodeValue);
		return closestNodeValue[0];
	}
	
	private static void findClosest(TreeNode node, double target, double diff, int[] closest){
		if(node==null) return;
		if(Math.abs(target-(double)node.val)>Integer.MAX_VALUE)
			closest[0]=Math.min(closest[0], node.val);
		else{
			if(Math.abs(target-(double)node.val)<=diff){
				diff=Math.abs(target-(double)node.val);
				closest[0]=node.val;
			}
		}
		findClosest(node.left, target, diff, closest);
		findClosest(node.right, target, diff, closest);
	}

	//Closest BST value II
	public static List<Integer> closestKValues(TreeNode root, double target, int k) {
		Stack<Integer> predecessor=new Stack<>();
		Stack<Integer> successor=new Stack<>();
		inorderTraverse(root, target, false, predecessor);	//Forward inorder traverse
		inorderTraverse(root, target, true, successor);	//Reverse inorder traverse

        List<Integer> closest=new ArrayList<>();
		while(k>0){
			if(predecessor.isEmpty()) closest.add(successor.pop());
			else if(successor.isEmpty()) closest.add(predecessor.pop());
			else{
				double minPredecessor=Math.abs((double)predecessor.peek()-target);
				double minSuccesor=Math.abs((double)successor.peek()-target);
				if(minPredecessor<minSuccesor)
					closest.add(predecessor.pop());
				else
					closest.add(successor.pop());
				
			}
			k--;
		}
        return closest;
	}
	
	private static void inorderTraverse(TreeNode node, double target, boolean isReverese, Stack<Integer> stack){
		if(node==null) return;
		inorderTraverse(isReverese?node.right:node.left, target, isReverese, stack);
		if((isReverese && node.val<=target) || (!isReverese && node.val>=target)) return;	//Found the crossover point
		stack.push(node.val);
		inorderTraverse(isReverese?node.left:node.right, target, isReverese, stack);
	}
	
	public static void main(String[] args){
		TreeNode root=new TreeNode(1);
//		root.left=new TreeNode(30);
//		root.right=new TreeNode(50);
//		root.left.left=new TreeNode(16);
//		root.left.right=new TreeNode(35);
//		root.right.left=new TreeNode(45);
//		root.right.right=new TreeNode(55);
//		root.left.left.left=new TreeNode(12);
//		root.left.left.right=new TreeNode(22);
//		root.right.left.right=new TreeNode(48);
//		root.right.right.left=new TreeNode(53);
//		root.right.right.right=new TreeNode(56);
		
		TreeNode.printBinaryTree(root, 0);
		double target=0.00;
		int k=1;
		System.out.println("The closest node value to "+target+" is: "+closestValue(root, target));
		System.out.println("The cloest "+k+" node values to "+target+" are: "+Arrays.deepToString(closestKValues(root, target, k).toArray()));
	}
}