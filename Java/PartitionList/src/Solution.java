
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
	
	public static ListNode partition(ListNode head, int x){
        if(head==null || head.next==null) return head;
		ListNode preHead=new ListNode(0);
		preHead.next=head;
		head=preHead;
		ListNode save=head,curr=head.next;
		while(curr!=null && curr.val<x){
			save=curr;
			curr=curr.next;
		}
		if(curr!=null){
			ListNode prev=curr;
			while(curr!=null){
				if(curr.val>=x){
					prev=curr;
					curr=curr.next;
					continue;
				}
				ListNode next=curr.next;
				curr.next=save.next;
				save.next=curr;
				save=curr;
				prev.next=next;
				curr=next;
			}
		}
		head=head.next;
		preHead.next=null;
		return head;
	}
	
	public static void main(String[] args){
		ListNode head=new ListNode(1);
		ListNode print=head;
		ListNode tail=head;
		tail.next=new ListNode(4);
		tail=tail.next;
		tail.next=new ListNode(3);
		tail=tail.next;
		tail.next=new ListNode(2);
		tail=tail.next;
		tail.next=new ListNode(5);
		tail=tail.next;
		tail.next=new ListNode(2);
		tail=tail.next;

		System.out.print("The singly-linked list is: ");
		ListNode.printList(print);
		int x=3;
		System.out.print("After partitioning by "+x+", the list becomes: ");
		ListNode.printList(partition(head, x));
	}
}