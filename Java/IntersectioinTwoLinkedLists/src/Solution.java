
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
	
	public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA==null || headB==null) return null;
        ListNode pA=headA, pB=headB;
        int lenA=0, lenB=0;
        while(pA!=null){
        	lenA++;
        	pA=pA.next;
        }
        while(pB!=null){
        	lenB++;
        	pB=pB.next;
        }
        int lenDiff=0;
        ListNode curr1=null, curr2=null;
        if(lenA>lenB){
        	lenDiff=lenA-lenB;
        	curr1=headA;
        	curr2=headB;
        }
        else{
        	lenDiff=lenB-lenA;
        	curr1=headB;
        	curr2=headA;
        }
        
        int count=0;
        while(count<lenDiff && curr1.next!=null){
        	count++;
        	curr1=curr1.next;
        }
        
        while(curr1!=null && curr2!=null){
        	if(curr1.val==curr2.val) return curr1;
        	curr1=curr1.next;
        	curr2=curr2.next;
        }
        return null;
        
    }
	
	public static void main(String[] args) {
		//First list
		ListNode headA=new ListNode(-2);
		ListNode printA=headA, tailA=headA;
		ListNode headA_1=new ListNode(-1);
		tailA.next=headA_1;
		tailA=tailA.next;
		ListNode headA_2=new ListNode(0);
		tailA.next=headA_2;
		tailA=tailA.next;
		ListNode headA_3=new ListNode(1);
		tailA.next=headA_3;
		tailA=tailA.next;
		ListNode headA_4=new ListNode(4);
		tailA.next=headA_4;
		tailA=tailA.next;
		ListNode headA_5=new ListNode(5);
		tailA.next=headA_5;
		tailA=tailA.next;
		ListNode headA_6=new ListNode(6);
		tailA.next=headA_6;
		tailA=tailA.next;
		System.out.print("List A: ");
		ListNode.printList(printA);
		
		//Second list
		ListNode headB=new ListNode(1);
		ListNode printB=headB, tailB=headB;
		ListNode headB_1=new ListNode(2);
		tailB.next=headB_1;
		tailB=tailB.next;
		ListNode headB_2=new ListNode(3);
		tailB.next=headB_2;
		tailB=tailB.next;
		ListNode headB_3=new ListNode(4);
		tailB.next=headB_3;
		tailB=tailB.next;
		ListNode headB_4=new ListNode(5);
		tailB.next=headB_4;
		tailB=tailB.next;
		ListNode headB_5=new ListNode(6);
		tailB.next=headB_5;
		tailB=tailB.next;
		System.out.print("List B: ");
		ListNode.printList(printB);
		
		ListNode intersection=getIntersectionNode(headA, headB);
		System.out.print("The intersection node is: ");
		System.out.println(intersection==null?"null":intersection.val);
	}
}
