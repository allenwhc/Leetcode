/*
*	Remove nth Node from End of List
*
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
	ListNode* removeNthFromEnd(ListNode *head, int n){
		ListNode *p = head;
		if (head == NULL || head->next == NULL) return NULL;
		int length = 0;
		while (p != NULL) {
			p = p->next;
			length++;
		}
		if (n == length){
			ListNode *p1 = head;
			head = head->next;
			delete p1;
			return head;
		}
		else{
			ListNode *p2 = head, *p3 = head;
			for (int i = 0; i < length - n; i++){
				p3 = p2;
				p2 = p2->next;
			}
			p3->next = p2->next;
			delete p2;
			return head;
		}
	}
};

void main(int argc, char *argv[]){
	ListNode *head = new ListNode(1);
	ListNode *print = head;
	ListNode *tail = head;
	ListNode *node1 = new ListNode(2);
	tail->next = node1;
	tail = tail->next;
	ListNode *node2 = new ListNode(3);
	tail->next = node2;
	tail = tail->next;
	ListNode *node3 = new ListNode(4);
	tail->next = node3;
	tail = tail->next;
	ListNode *node4 = new ListNode(5);
	tail->next = node4;
	tail = tail->next;

	cout << "The original list is: ";
	while (print != NULL){
		cout << print->val;
		print = print->next;
		if (print != NULL) cout << "->";
	}
	cout << endl;
	Solution s;
	int n = 2;
	ListNode *remove = s.removeNthFromEnd(head, n);
	cout << "The list of which removes the " << n << "th node from the end is: ";
	while (remove != NULL){
		cout << remove->val;
		remove = remove->next;
		if (remove != NULL) cout << "->";
	}
	cout << endl;
	system("pause");
}