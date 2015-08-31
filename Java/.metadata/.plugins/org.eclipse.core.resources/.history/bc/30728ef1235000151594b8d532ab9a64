import java.util.LinkedList;
import java.util.Queue;

public class Solution {
	public static class Pair{
		TreeLinkNode node;
		int level;
		Pair(TreeLinkNode n, int val) {
			node=n;
			level=val;
		}
	}
	//Populate next right pointer I, perfect binary tree
	public static void connect(TreeLinkNode root){
		if(root==null) return;
		root.next=null;
		setNextPointer(root);
	}
	
	private static void setNextPointer(TreeLinkNode node){
		if(node==null) return;
		if(node.left!=null)
			node.left.next=node.right;
		if(node.right!=null)
			node.right.next=node.next==null?null:node.next.left;
		setNextPointer(node.left);
		setNextPointer(node.right);
	}
	
	//Populate next right pointer II, imperfect binary tree
	public static void connect2(TreeLinkNode root){
		if(root==null) return;
		root.next=null;
		int treeLevel=0;
		TreeLinkNode node=root;
		Queue<Pair> q=new LinkedList<>();
		q.offer(new Pair(root, 0));
		while(true){
			treeLevel=q.peek().level+1;
			if(node.left!=null)
				q.offer(new Pair(node.left, treeLevel));
			if(node.right!=null)
				q.offer(new Pair(node.right, treeLevel));
			if(q.size()==1) break;	//Only on element left in the queue
			Pair p=q.poll();
			if(p.level==q.peek().level)
				p.node.next=q.peek().node;
			else
				p.node.next=null;
			node=q.peek().node;
		}
		node.next=null;
	}
	
	public static void printNextPointer(TreeLinkNode node){
		if(node==null) return;
		System.out.print("The next right node of "+node.val+" is ");
		if(node.next==null)
			System.out.println("null");
		else
			System.out.println(node.next.val);
		printNextPointer(node.left);
		printNextPointer(node.right);
	}
	
	public static void main(String[] args){
		System.out.println("Perfect Binary Tree: ");
		TreeLinkNode root=new TreeLinkNode(1);
		root.left=new TreeLinkNode(2);
		root.right=new TreeLinkNode(3);
		root.left.left=new TreeLinkNode(4);
		root.left.right=new TreeLinkNode(5);
		root.right.left=new TreeLinkNode(6);
		root.right.right=new TreeLinkNode(7);
		connect(root);
		printNextPointer(root);
		System.out.println("Imperfect Binary Tree: ");
		TreeLinkNode root2=new TreeLinkNode(1);
		root2.left=new TreeLinkNode(2);
		root2.right=new TreeLinkNode(3);
		root2.left.left=new TreeLinkNode(4);
		root2.left.right=new TreeLinkNode(5);
		root2.right.right=new TreeLinkNode(7);

		connect2(root2);
		printNextPointer(root2);
	}
}
