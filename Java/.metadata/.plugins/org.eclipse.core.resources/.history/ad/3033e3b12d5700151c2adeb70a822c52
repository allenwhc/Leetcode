
public class Solution {
	public static class ListNode{
		int val;
		ListNode next;
		public ListNode(int x) {
			val=x;
			next=null;
		}
		
		public static void printList(ListNode head){
			while(head!=null){
				System.out.print(head.val);
				head=head.next;
				if(head!=null) System.out.print("->");
			}
			System.out.println();
		}
	}
	
	public static void deleteNode(ListNode node){
		if(node==null || node.next==null) return;
		ListNode temp=new ListNode(0);
		temp=node.next;
		node.val=temp.val;
		node.next=temp.next;
		temp=null;
	}
	
	public static void main(String[] args) {
		ListNode head=new ListNode(1);
		ListNode print=head, tail=head;
		ListNode n1=new ListNode(2);
		tail.next=n1;
		tail=tail.next;
		ListNode n2=new ListNode(3);
		tail.next=n2;
		tail=tail.next;
		ListNode n3=new ListNode(4);
		tail.next=n3;
		tail=tail.next;
		
		System.out.print("The original list is: ");
		ListNode.printList(print);
		ListNode node=n2;
		System.out.print("After delete "+node.val+", the list is: ");
		deleteNode(node);
		ListNode.printList(head);
	}
}
