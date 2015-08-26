/*
*	Sort List
*	Last Modified: 6/15/2015
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
	ListNode* sortList(ListNode *head){
		if (head == NULL || head->next == NULL) return head;
		else{
			ListNode *fast = head, *slow = head;
			while (fast->next != NULL && fast->next->next != NULL){
				fast = fast->next->next;	//FAST gets 2 hops
				slow = slow->next;	//SLOW gets 1 hop
			}
			fast = slow;
			slow = slow->next;
			fast->next = NULL; //Divides the list into two parts
			fast = sortList(head);
			slow = sortList(slow);	//recursively divides the list into two equal length parts
			cout << fast->val << ", " << slow->val << endl;
			return mergeSort(fast, slow);
		}
	}
	ListNode* mergeSort(ListNode *head1, ListNode *head2){
		if (head1 == NULL) return head2;
		if (head2 == NULL) return head1;
		ListNode *result, *p;
		if (head1->val < head2->val){
			result = head1;
			head1 = head1->next;
		}
		else{
			result = head2;
			head2 = head2->next;
		}
		p = result;
		while (head1 != NULL && head2 != NULL){
			if (head1->val < head2->val){
				p->next = head1;
				head1 = head1->next;
			}
			else{
				p->next = head2;
				head2 = head2->next;
			}
			p = p->next;
		}
		if (head1 != NULL) p->next = head1;
		else if (head2 != NULL) p->next = head2;
		return result;
	}
};

void main(int argc, char *argv[]){
	ListNode *head = new ListNode(6);
	ListNode *print = head;
	ListNode *tail = head;
	ListNode *node1 = new ListNode(5);
	tail->next = node1;
	tail = tail->next;
	ListNode *node2 = new ListNode(3);
	tail->next = node2;
	tail = tail->next;
	ListNode *node3 = new ListNode(1);
	tail->next = node3;
	tail = tail->next;
	ListNode *node4 = new ListNode(7);
	tail->next = node4;
	tail = tail->next;
	ListNode *node5 = new ListNode(8);
	tail->next = node5;
	tail = tail->next;
	ListNode *node6 = new ListNode(2);
	tail->next = node6;
	tail = tail->next;
	ListNode *node7 = new ListNode(4);
	tail->next = node7;
	tail = tail->next;

	int n = 0;
	cout << "The unsorted list is: ";
	while (print != NULL){
		cout << print->val;
		n++;
		print = print->next;
		if (print != NULL) cout << "->";
	}
	cout << endl;
	Solution s;
	ListNode *result = s.sortList(head);
	cout << "The sorted list is: ";
	while (result != NULL){
		cout << result->val;
		result = result->next;
		if (result != NULL) cout << "->";
	}
	cout << endl;
	system("pause");
}