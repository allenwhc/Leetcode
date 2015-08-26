class ListNode{
		int val;
		ListNode next;
		ListNode(int x) {
			val=x;
			next=null;
		}
	}

public class Solution {
	//Linked List I, detect if the list has cycle
	public static boolean hasCycle(ListNode head){
		if(head==null) return false;
		ListNode slow=head, fast=head;
		while(true){
			slow=slow.next;
			if(fast.next!=null)
				fast=fast.next.next;
			else return false;
			if(fast==null || slow==null) return false;
			if(slow==fast) return true;
		}
	}
	
	//Linked List II, detect where the cycle starts
	public static ListNode detectCycle(ListNode head){
		if(head==null) return null;
		ListNode slow=head, fast=head;
		while(true){
			slow=slow.next;
			if(fast.next!=null)
				fast=fast.next.next;
			else return null;
			if(fast==null || slow==null) return null;
			if(slow==fast) break;
		}
		
		//Move fast pointer back to the head
		for(fast=head; fast!=slow; fast=fast.next)
			slow=slow.next;
		return slow;
	}
	
	public static void main(String[] args){
		ListNode head=new ListNode(1);
		ListNode tail=head;
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
		tail.next=n2;
		tail=tail.next;
		
		if(hasCycle(head)){
			System.out.println("The linked list has cycle.");
			System.out.println("The cycle starts from "+detectCycle(head).val);
		}
		else
			System.out.println("The linked list doesn't have cycle.");
	}
}
