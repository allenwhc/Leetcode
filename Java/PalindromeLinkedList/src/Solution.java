
public class Solution {
	public static boolean isPalindrome(ListNode head){
		if(head==null || head.next==null) return true;
		ListNode fast=head, slow=head;
		ListNode prev=head;
		//First, find the mid point of list
		while(fast!=null && fast.next!=null){
			prev=slow;	//Save previous position of slow pointer
			slow=slow.next;
			fast=fast.next.next;
		}
		prev.next=null;	//Terminate the first half
		//System.out.println("prev="+prev.val+", slow="+slow.val+", fast="+fast.val);
		
		ListNode head2Half=null;
		if(fast!=null){
			//The size of list is odd
			head2Half=slow.next;
		}
		else head2Half=slow;
		//System.out.println("head of 2nd half="+head2Half.val);
		
		//Reverse the second half
		ListNode curr=head2Half;
		ListNode next=head2Half.next;
		while(curr!=null && next!=null){
			ListNode tmp=next.next;
			next.next=curr;
			curr=next;
			if(tmp!=null) next=tmp;
			else break;
		}
		head2Half=curr;	//Update the head of 2nd half
		
		//Compare first half and reversed 2nd half
		while(head!=null && head2Half!=null){
			if(head.val!=head2Half.val) return false;
			head=head.next;
			head2Half=head2Half.next;
		}
		return true;
	}
	
	public static void main(String[] args){
		ListNode head=new ListNode(1);
		ListNode print=head;
		ListNode tail=head;
		ListNode n1=new ListNode(2);
		tail.next=n1;
		tail=tail.next;
		ListNode n2=new ListNode(4);
		tail.next=n2;
		tail=tail.next;
		ListNode n3=new ListNode(5);
		tail.next=n3;
		tail=tail.next;
		ListNode n4=new ListNode(4);
		tail.next=n4;
		tail=tail.next;
		ListNode n5=new ListNode(2);
		tail.next=n5;
		tail=tail.next;
		ListNode n6=new ListNode(1);
		tail.next=n6;
		tail=tail.next;
		
		System.out.print("The singly linked list is: ");
		while(print!=null){
			System.out.print(print.val);
			print=print.next;
			if(print!=null) System.out.print("->");
		}
		System.out.println();
		if(isPalindrome(head))
			System.out.println("The list is palindrome");
		else
			System.out.println("The list is not palindrome");
	}
}
