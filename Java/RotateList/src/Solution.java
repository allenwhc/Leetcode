
public class Solution {
	public static class ListNode{
		int val;
		ListNode next;
		public ListNode(int x) {
			val=x;
			next=null;
		}
		
		public static void print(ListNode head){
			while(head!=null){
				System.out.print(head.val);
				head=head.next;
				if(head!=null) System.out.print("->");
			}
			System.out.println();
		}
	}
	
	public static ListNode rotateRight(ListNode head, int k){
		 	if(head==null || head.next==null) return head;
			int len=0;
			ListNode p=head;
			while(p!=null){
				p=p.next;
				len++;
			}
			k=k%len;
			if(k==0) return head;	//k=0, no need to rotate
			ListNode preHead=new ListNode(0);
			preHead.next=head;
			head=preHead;
			ListNode prev=head, curr=head.next;
			int i=0;
			while(i<len-k){
				prev=curr;
				curr=curr.next;
				i++;
			}
			prev.next=null;	//Set new tail
			ListNode temp=head.next;	//Save current head
			head.next=curr;	//Set new head
			while(curr.next!=null) curr=curr.next;	//Iterate to the end of original list
			curr.next=temp;
			head=head.next;
			preHead.next=null;
			return head;
	}
	
	public static void main(String[] args) {
		ListNode head=new ListNode(1);
		ListNode tail=head, print=head;
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
		System.out.print("The original list is: ");
		ListNode.print(print);
		int k=5;
		System.out.print("The rotated list is: ");
		ListNode.print(rotateRight(head, k));
	}
}