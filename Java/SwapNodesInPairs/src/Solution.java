
public class Solution {
	 public static class ListNode {
		 int val;
		 ListNode next;
		 ListNode(int x) { val = x; }
		 
		 public static void print(ListNode head){
			 while(head!=null){
				 System.out.print(head.val);
				 head=head.next;
				 if(head!=null) System.out.print("->");
			 }
			 System.out.println();
		 }
	 }
	 
	 public static ListNode swapPairs(ListNode head) {
		 if(head==null || head.next==null) return head;
		 ListNode prev=head, curr=head.next;
		 head=curr;
		 ListNode temp=new ListNode(0);
		 while(curr!=null){
			 ListNode next=curr.next;
			 curr.next=prev;
			 temp.next=curr;
			 prev.next=next;
			 temp=prev;
			 prev=next;
			 if(next==null) break;
			 else curr=next.next;
		 }

		 return head;
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
		ListNode n4=new ListNode(5);
		tail.next=n4;
		tail=tail.next;
		ListNode n5=new ListNode(6);
		tail.next=n5;
		tail=tail.next;
		System.out.print("The original list is: ");
		ListNode.print(print);
		System.out.print("The pair-swapped list is: ");
		ListNode.print(swapPairs(head));
	}
}