import java.util.Arrays;

public class Solution {
	public static TreeNode sortedArrayToBST(int[] nums){
		int n=nums.length;
		if(n==0) return null;
		return constructTreeArray(nums, 0, n-1);
	}
	
	private static TreeNode constructTreeArray(int[] nums, int start, int end){
		if(start>end) return null;
		int middle=(start+end)/2;
		TreeNode node=new TreeNode(nums[middle]);
		node.left=constructTreeArray(nums, start, middle-1);
		node.right=constructTreeArray(nums, middle+1, end);
		return node;
	}
	
	public static TreeNode sortedListToBST(ListNode head) {
        if(head==null) return null;
        ListNode p=head;
        int len=0;
        while(p!=null){
        	len++;
        	p=p.next;
        }
        return constructTreeList(head, 0, len-1);
    }
	
	private static TreeNode constructTreeList(ListNode head, int start, int end){
		if(start>end) return null;
		int middle=(start+end)/2;
		ListNode p=head;
		for(int i=start ;i<middle; i++)
			p=p.next;
		TreeNode node=new TreeNode(p.val);
		node.left=constructTreeList(head, start, middle-1);
		node.right=constructTreeList(p.next, middle+1, end);
		return node;
	}
	
	public static void main(String[] args){
		int[] nums={1,2,3,4,5,6,7};
		System.out.println("The sorted array is: "+ Arrays.toString(nums));
		System.out.println("The BST is: ");
		TreeNode.printBinaryTree(sortedArrayToBST(nums), 0);
		
		ListNode head=new ListNode(1);
		ListNode print=head;
		ListNode tail=head;
		ListNode n1=new ListNode(3);
		tail.next=n1;
		tail=tail.next;
		ListNode n2=new ListNode(5);
		tail.next=n2;
		tail=tail.next;
		ListNode n3=new ListNode(7);
		tail.next=n3;
		tail=tail.next;
		ListNode n4=new ListNode(9);
		tail.next=n4;
		tail=tail.next;
		ListNode n5=new ListNode(11);
		tail.next=n5;
		tail=tail.next;
		ListNode n6=new ListNode(13);
		tail.next=n6;
		tail=tail.next;
		
		System.out.print("The sorted list is: ");
		while(print!=null){
			System.out.print(print.val);
			print=print.next;
			if(print!=null) System.out.print("->");
		}
		System.out.println();
		System.out.println("The BST is: ");
		TreeNode.printBinaryTree(sortedListToBST(head), 0);
		
	}
}
