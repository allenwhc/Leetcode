
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
	
	//Sort List Using 
	public static ListNode sortList(ListNode head){
		if(head==null || head.next==null) return head;
		ListNode midNode=split(head);
		ListNode secondHead=midNode.next;
		midNode.next=null;
		return mergeSort(sortList(head), sortList(secondHead));
	}
	
	private static ListNode mergeSort(ListNode head1, ListNode head2){
		ListNode p=new ListNode(0);
		ListNode curr=p;
		while(head1!=null && head2!=null){
			if(head1.val<=head2.val){
				curr.next=head1;
				head1=head1.next;
			}
			else{
				curr.next=head2;
				head2=head2.next;
			}
			curr=curr.next;
		}
		curr.next=(head1==null)?head2:head1;
		return p.next;
	}
	
	private static ListNode split(ListNode head){
		if(head==null) return null;
		ListNode slow=head, fast=head;
		while(fast.next!=null && fast.next.next!=null){
			slow=slow.next;
			fast=fast.next.next;
		}
		return slow;
	}
	
	public static void main(String[] args){
		ListNode head=new ListNode(4);
		ListNode print=head,prev=head;
		prev.next=head;
		prev=prev.next;
		ListNode n1=new ListNode(2);
		prev.next=n1;
		prev=prev.next;
		ListNode n2=new ListNode(3);
		prev.next=n2;
		prev=prev.next;
		ListNode n3=new ListNode(7);
		prev.next=n3;
		prev=prev.next;
		ListNode n4=new ListNode(5);
		prev.next=n4;
		prev=prev.next;
		ListNode n5=new ListNode(8);
		prev.next=n5;
		prev=prev.next;
		ListNode n6=new ListNode(6);
		prev.next=n6;
		prev=prev.next;
		System.out.print("The unsorted singly-linked list is: ");
		ListNode.printList(print);
		System.out.print("The sorted (Merge Sort) singly-linked list is: ");
		ListNode.printList(sortList(head));
	}
}