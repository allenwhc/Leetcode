/*
*	Palindrome Linked List
*	Last Modified: 7/21/2015
*	Hint:
		1) Get the middle of the linked list.
		2) Reverse the second half of the linked list.
		3) Check if the first half and second half are identical.
		4) Construct the original linked list by reversing the second half again and attaching it back to the first half
*/

#include <iostream>
using namespace std;

struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) return true;
		ListNode *fast = head, *slow = head;
		ListNode *midNode = NULL;
		ListNode *prev_slow = head;
		ListNode *head2Half;
		while (fast && fast->next){
			fast = fast->next->next;
			prev_slow = slow;
			slow = slow->next;
		}
		if (fast){
			//If fast!=NULL, then there is odd # of nodes in the list
			midNode = slow;
			slow = slow->next;	//Skip the middle node
		}

		head2Half = slow;
		prev_slow->next = NULL;	//Terminate the first half
		head2Half = reverseList(head2Half);	//Reverse the second half

		//Now, compare the first half to the reversed second half 
		bool isPalindrome = compareLists(head, head2Half);

		head2Half = reverseList(head2Half);		//Reverse back the second half
		if (midNode){
			prev_slow->next = midNode;
			midNode->next = head2Half;
		}
		else prev_slow->next = head2Half;
		return isPalindrome;
	}

	ListNode* reverseList(ListNode *head){
		if (!head || !head->next) return head;
		ListNode *prev = head;
		ListNode *curr = head->next;
		head->next = NULL;
		while (prev && curr){
			ListNode *next = curr->next;
			curr->next = prev;
			prev = curr;
			if (next) curr = next;
			else break;
		}
		return curr;
	}

	bool compareLists(ListNode *head1, ListNode *head2){
		ListNode *temp1 = head1;
		ListNode *temp2 = head2;

		while (temp1 && temp2){
			if (temp1->val == temp2->val){
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			else return false;
		}
		if (!temp1 && !temp2) return true;
		return false;
	}
};

void main(int argc, char *argv[]){
	ListNode *headA = new ListNode(1);
	ListNode *tailA = headA;
	ListNode *printA = headA;
	ListNode *A1 = new ListNode(2);
	tailA->next = A1;
	tailA = tailA->next;
	ListNode *A2 = new ListNode(3);
	tailA->next = A2;
	tailA = tailA->next;
	ListNode *A3 = new ListNode(4);
	tailA->next = A3;
	tailA = tailA->next;
	ListNode *A4 = new ListNode(5);
	tailA->next = A4;
	tailA = tailA->next;
	ListNode *A5 = new ListNode(6);
	tailA->next = A5;
	tailA = tailA->next;
	ListNode *A6 = new ListNode(7);
	tailA->next = A6;
	tailA = tailA->next;
	ListNode *A7 = new ListNode(8);
	tailA->next = A7;
	tailA = tailA->next;

	Solution s;
	cout << "List: ";
	while (printA){
		cout << printA->val;
		printA = printA->next;
		if (printA) cout << "->";
	}
	if (s.isPalindrome(headA)) cout << " is palindrome" << endl;
	else cout << " is not palindrome" << endl;

	ListNode *headB = new ListNode(1);
	ListNode *tailB = headB;
	ListNode *printB = headB;
	ListNode *B1 = new ListNode(2);
	tailB->next = B1;
	tailB = tailB->next;
	ListNode *B2 = new ListNode(3);
	tailB->next = B2;
	tailB = tailB->next;
	ListNode *B3 = new ListNode(4);
	tailB->next = B3;
	tailB = tailB->next;
	ListNode *B4 = new ListNode(4);
	tailB->next = B4;
	tailB = tailB->next;
	ListNode *B5 = new ListNode(3);
	tailB->next = B5;
	tailB = tailB->next;
	ListNode *B6 = new ListNode(2);
	tailB->next = B6;
	tailB = tailB->next;
	ListNode *B7 = new ListNode(1);
	tailB->next = B7;
	tailB = tailB->next;

	cout << "List: ";
	while (printB){
		cout << printB->val;
		printB = printB->next;
		if (printB) cout << "->";
	}
	if (s.isPalindrome(headB)) cout << " is palindrome" << endl;
	else cout << " is not palindrome" << endl;
	system("pause");
}