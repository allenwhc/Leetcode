
public class Solution {
	//Remove duplicates from sorted list I
	public static ListNode deleteDuplicates1(ListNode head){
		if(head==null || head.next==null) return head;
		ListNode prev=head;
		ListNode curr=head.next;
		while(curr!=null){
			if(curr.val==prev.val){
				ListNode next=curr.next;
				prev.next=next;
				curr=next;
			}
			else{
				prev=curr;
				curr=curr.next;
			}
		}
		return head;
	}
	
	//Remove duplicates from sorted list II, reserve only non-duplicate nodes
	public static ListNode deleteDuplicates2(ListNode head){
		if(head==null) return null;
		ListNode temp=new ListNode(Integer.MIN_VALUE);
		temp.next=head;
		ListNode curr=temp;
		while(curr.next!=null && curr.next.next!=null){
			if(curr.next.val==curr.next.next.val){
				int val=curr.next.val;
				while(curr.next!=null && curr.next.val==val){
					curr.next=curr.next.next;
				}
			}
			else curr=curr.next;
 		}
		return temp.next;
	}
	
	//Main
	public static void main(String[] args){
		ListNode head=new ListNode(1);
		ListNode tail=head;
		ListNode print=head;
		ListNode n1=new ListNode(2);
		tail.next=n1;
		tail=tail.next;
		ListNode n2=new ListNode(3);
		tail.next=n2;
		tail=tail.next;
		ListNode n3=new ListNode(3);
		tail.next=n3;
		tail=tail.next;
		ListNode n4=new ListNode(4);
		tail.next=n4;
		tail=tail.next;
		ListNode n5=new ListNode(4);
		tail.next=n5;
		tail=tail.next;
		ListNode n6=new ListNode(5);
		tail.next=n6;
		tail=tail.next;
		System.out.print("The original linked list is: ");
		while(print!=null){
			System.out.print(print.val);
			print=print.next;
			if(print!=null) System.out.print("->");
		}
		System.out.println();
		ListNode res1=deleteDuplicates1(head);
		System.out.print("The revised linked list is (save duplicate nodes): ");
		while(res1!=null){
			System.out.print(res1.val);
			res1=res1.next;
			if(res1!=null) System.out.print("->");
		}
		System.out.println();
		
		
		ListNode head2=new ListNode(1);
		ListNode tail2=head2;
		ListNode n21=new ListNode(2);
		tail2.next=n21;
		tail2=tail2.next;
		ListNode n22=new ListNode(3);
		tail2.next=n22;
		tail2=tail2.next;
		ListNode n23=new ListNode(3);
		tail2.next=n23;
		tail2=tail2.next;
		ListNode n24=new ListNode(4);
		tail2.next=n24;
		tail2=tail2.next;
		ListNode n25=new ListNode(4);
		tail2.next=n25;
		tail2=tail2.next;
		ListNode n26=new ListNode(5);
		tail2.next=n26;
		tail2=tail2.next;
		ListNode res2=deleteDuplicates2(head2);
		System.out.print("The revised linked list is (delete all duplicate nodes): ");
		while(res2!=null){
			System.out.print(res2.val);
			res2=res2.next;
			if(res2!=null) System.out.print("->");
		}
	}
}
