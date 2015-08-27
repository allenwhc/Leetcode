import java.util.Arrays;

public class Solution {
	public static TreeNode buildTree1(int[] preorder, int[] inorder){
		int n=inorder.length;
		if(n==0) return null;
		return constructInorderPreorder(preorder, inorder, 0, 0, n-1);
	}
	
	private static TreeNode constructInorderPreorder(int[] preorder, int[] inorder, int index, int start, int end){
		if(start>end) return null;
		TreeNode node =new TreeNode(preorder[index]);
		if(start==end) return node;
		int i=start;
		for(; i<=end; i++)
			if(node.val==inorder[i])
				break;
		//System.out.println(inorder_index);
		node.left=constructInorderPreorder(preorder, inorder, index+1, start, i-1);
		node.right=constructInorderPreorder(preorder, inorder, index+1+i-start, i+1, end);
		return node;
	}
	
	public static TreeNode buildTree2(int[] inorder, int[] postorder) {
        int n=postorder.length;
        if(n==0) return null;
        return constructInorederPostorder(inorder, postorder, n-1, 0, n-1);
    }
	
	private static TreeNode constructInorederPostorder(int[] inorder, int[] postorder, int index, int start, int end){
		if(start>end) return null;
		TreeNode node=new TreeNode(postorder[index]);
		if(start==end) return node;
		int i=start;
		for(; i<=end; i++)
			if(node.val==inorder[i])
				break;
		node.right=constructInorederPostorder(inorder, postorder, index-1, i+1, end);
		node.left=constructInorederPostorder(inorder, postorder, index-1-end+i, start, i-1);
		return node;
	}
	
	public static void main(String[] args){
		int[] preorder={1,2,4,5,3,6,7};
		int[] inorder={4,2,5,1,6,3,7};
		int[] postorder={4,5,2,6,7,3,1};
		
		System.out.println("The preorder traversal of binary tree is: "+Arrays.toString(preorder));
		System.out.println("The inorder traversal of binary tree is: "+Arrays.toString(inorder));
		System.out.println("The postorder traversal of binary tree is: "+Arrays.toString(postorder));
		
		System.out.println("The binary constructed from preorder and inorder traversal is: ");
		TreeNode.printBinaryTree(buildTree1(preorder, inorder), 0);
		
		System.out.println("The binary constructed from postorder and inorder traversal is: ");
		TreeNode.printBinaryTree(buildTree2(inorder, postorder), 0);
	}
}
