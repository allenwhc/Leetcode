/*
*	Reverse Nodes in K-Group
*	Last Modified: 7/1/2015
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
	ListNode* reverseKGroup(ListNode* head, int k){
		if (head == NULL) return head;
		ListNode *p = head;
		int count = k;
		while (--count&&p){
			p = p->next; 
		}
		if (!p) return head;
		ListNode *next = p->next, *temp = head;
		p->next = NULL; 
		head = reverse(head);
		temp->next = reverseKGroup(next, k);
		return head;
	}

	ListNode* reverse(ListNode *head){
		ListNode* p = head, *temp = NULL;
		while (p){
			ListNode *next = p->next; 
			p->next = temp;
			temp = p;
			p = next;
		}
		return temp;
	}
};

void main(int argc, char* argv[]){
	ListNode *head = new ListNode(1);
	ListNode *print = head;
	ListNode *tail = head;
	ListNode *n1 = new ListNode(2);
	tail->next = n1;
	tail = tail->next;
	ListNode *n2 = new ListNode(3);
	tail->next = n2;
	tail = tail->next;
	ListNode *n3 = new ListNode(4);
	tail->next = n3;
	tail = tail->next;
	ListNode *n4 = new ListNode(5);
	tail->next = n4;
	tail = tail->next;
	/*ListNode *n5 = new ListNode(6);
	tail->next = n5;
	tail = tail->next;*/
	cout << "The input linked list is: ";
	while (print != NULL){
		cout << print->val;
		print = print->next;
		if (print != NULL) cout << "->";
	}
	cout << endl;
	Solution s;
	int k = 3;
	ListNode *res = s.reverseKGroup(head, k);
	cout << "The reversed linked list is: ";
	while (res != NULL){
		cout << res->val;
		res = res->next;
		if (res != NULL) cout << "->";
	}
	cout << endl;
	system("pause");
}