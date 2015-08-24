/*
*	Linked List Cycle I & II
*	Last Modified: 6/30/2015
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	//Linked List Cycle I, determines if a list has a cycle in it.
	bool hasCycle(ListNode* head){
		if (head == NULL) return false;
		ListNode *slow = head, *fast = head;
		while (1){
			slow = slow->next;	//slow pointer gets 1 hop
			if (fast->next) fast = fast->next->next;	//fast pointer gets 2 hop
			else return false;	//No cycle
			if (!slow || !fast) return false;
			if (slow == fast) return true;
		}
	}

	//Linked List Cycle II, detects where the loop starts
	ListNode* detectCycle(ListNode *head){
		if (head == NULL || head->next == NULL) return NULL;
		ListNode *slow = head, *fast = head;
		while (1){
			slow = slow->next;
			if (fast->next) fast = fast->next->next;
			else return NULL;
			if (!slow || !fast) return NULL;
			if (slow == fast) break;
		}
		for (fast = head; fast != slow; fast = fast->next) slow = slow->next;
		return slow;
	}
};

void main(int argc, char* argv[]){
	Solution s;
	ListNode* head = new ListNode(1);
	ListNode *tail = head;
	ListNode* n1 = new ListNode(2);
	tail->next = n1;
	tail = tail->next;
	ListNode* n2 = new ListNode(3);
	tail->next = n2;
	tail = tail->next;
	ListNode* n3 = new ListNode(4);
	tail->next = n3;
	tail = tail->next;
	ListNode* n4 = new ListNode(5);
	tail->next = n4;
	tail = tail->next;
	ListNode* n5 = new ListNode(6);
	tail->next = n5;
	tail = tail->next;
	tail->next = n2;
	tail = tail->next;

	bool hasCycle = s.hasCycle(head);	
	ListNode *startNode = s.detectCycle(head);
	cout << "The given linked list ";
	if (hasCycle){
		cout << "has loop" << endl;
		cout << "The loop starts from " << startNode->val << endl;
	}
	else cout << "doesn't have loop" << endl;


	system("pause");
}