
public class Solution {
	public static ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null) return null;
        ListNode preHead=new ListNode(0);
        preHead.next=head;
        head=preHead;
        int length=0;
        ListNode p1=head.next;
        while(p1!=null){
        	length++;
        	p1=p1.next;
        }
        
        ListNode curr=head.next;	//current node
        ListNode prev=head;		//previous node
        for(int i=0; i<length-n; i++){
        	prev=prev.next;
        	curr=curr.next;
        }
        ListNode next=curr.next;
        prev.next=next;
        head=head.next;
        preHead=null;
        return head;
    }
	
	public static void main(String[] args) {
		ListNode head=new ListNode(1);
		ListNode print=head;
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
		
		int n=5;
		System.out.print("The singly-linked list is: ");
		while(print!=null){
			System.out.print(print.val);
			print=print.next;
			if(print!=null) System.out.print("->");
		}
		System.out.println();
		System.out.print("After deleting the "+n+"th node from the end, the list's become: ");
		ListNode newHead=removeNthFromEnd(head, n);
		while(newHead!=null){
			System.out.print(newHead.val);
			newHead=newHead.next;
			if(newHead!=null) System.out.print("->");
		}
	}
}
