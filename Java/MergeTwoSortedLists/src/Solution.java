
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
	
	public static ListNode mergeTwoLists(ListNode l1, ListNode l2){
		if(l1==null) return l2;
		else if(l2==null) return l1;
		ListNode newHead=new ListNode(0);
		ListNode curr=newHead;
		while(l1!=null && l2!=null){
			if(l1.val<=l2.val){
				curr.next=l1;
				l1=l1.next;
			}
			else{
				curr.next=l2;
				l2=l2.next;
			}
			curr=curr.next;
		}
		while(l1!=null){
			curr.next=l1;
			l1=l1.next;
			curr=curr.next;
		}
		while(l2!=null){
			curr.next=l2;
			l2=l2.next;
			curr=curr.next;
		}
		return newHead.next;
	}
	
	public static void main(String[] args) {
		ListNode l1=new ListNode(1);
		ListNode print1=l1, tail1=l1;
		ListNode l1_1=new ListNode(3);
		tail1.next=l1_1;
		tail1=tail1.next;
		ListNode l1_2=new ListNode(4);
		tail1.next=l1_2;
		tail1=tail1.next;
		ListNode l1_3=new ListNode(6);
		tail1.next=l1_3;
		tail1=tail1.next;
		ListNode l1_4=new ListNode(9);
		tail1.next=l1_4;
		tail1=tail1.next;
		System.out.print("The first sorted list is: ");
		ListNode.print(print1);
		
		ListNode l2=new ListNode(2);
		ListNode print2=l2, tail2=l2;
		ListNode l2_1=new ListNode(5);
		tail2.next=l2_1;
		tail2=tail2.next;
		ListNode l2_2=new ListNode(7);
		tail2.next=l2_2;
		tail2=tail2.next;
		ListNode l2_3=new ListNode(8);
		tail2.next=l2_3;
		tail2=tail2.next;
		ListNode l2_4=new ListNode(10);
		tail2.next=l2_4;
		tail2=tail2.next;
		System.out.print("The second sorted list is: ");
		ListNode.print(print2);
		
		System.out.print("The merged sorted list: ");
		ListNode.print(mergeTwoLists(l1,l2));
	}
}
