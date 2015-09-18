
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
	
	public static ListNode reverseBetween(ListNode head, int m, int n){
		if(head==null || head.next==null) return head;
		ListNode preHead=new ListNode(0);
		preHead.next=head;
		head=preHead;
		ListNode prev=head;
		int len=n-m;
		while(m>1){
			prev=prev.next;
			m--;
		}
		ListNode curr=prev.next, next=curr.next;
		if(len>=1){
			while(len>0 && next!=null){
				ListNode temp=next.next;
				next.next=curr;
				curr=next;
				next=temp;
				len--;
			}
			ListNode temp=prev.next;
			prev.next=curr;
			temp.next=next;
		}
		head=head.next;
		preHead.next=null;
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
		
		int m=2,n=4;
		System.out.print("The original list is: ");
		ListNode.print(print);
		System.out.print("The reversed list is: ");
		ListNode.print(reverseBetween(head,m,n));
	}
}
