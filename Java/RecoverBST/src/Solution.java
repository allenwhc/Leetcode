
public class Solution {
	public static void recoverTree(TreeNode root){
		if(root==null) return;
		TreeNode curr=root;
		TreeNode node1=null, node2=null, prev=null;
		while(curr!=null){
			if(curr.left==null){
				if(prev!=null && curr.val<prev.val){
					if(node1==null)
						node1=prev;
					node2=curr;
				}
				prev=curr;
				curr=curr.right;
			}
			else{
				TreeNode p=curr.left;
				while(p.right!=null && p.right!=curr)
					p=p.right;
				if(p.right==null){
					p.right=curr;
					curr=curr.left;
				}
				else{
					p.right=null;
					if(prev!=null && curr.val<prev.val){
						if(node1==null)
							node1=prev;
						node2=curr;
					}
					prev=curr;
					curr=curr.right;
				}
			}
		}

		if(node1!=null && node2!=null){
			int temp=node1.val;
			node1.val=node2.val;
			node2.val=temp;
			
		}
	}
	
	public static void main(String[] args){
		TreeNode root=new TreeNode(3);
	//	root.left=new TreeNode(10);
		root.right=new TreeNode(1);
		//root.left.left=new TreeNode(1);
		//root.left.right=new TreeNode(3);
		root.right.left=new TreeNode(2);
		//root.right.right=new TreeNode(12);
		System.out.println("The swapped BST is: ");
		TreeNode.printBinaryTree(root, 0);
		recoverTree(root);
		System.out.println("The corrected BST is: ");
		TreeNode.printBinaryTree(root, 0);
	}
}
