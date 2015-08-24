/*
*	Reverse Linked List I & II
*	Last Modified: 7/7/2015
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
	//Iterative
	ListNode* reverseList(ListNode *head){
		if (head == NULL || head->next == NULL) return head;
		ListNode *p1 = head;
		ListNode *p2 = head->next;
		head->next = NULL;
		while (p1 != NULL && p2 != NULL){
			ListNode *t = p2->next;
			p2->next = p1;
			p1 = p2;
			if (t != NULL) p2 = t;
			else break;
		}
		return p2;
	}

	//Recursive
	ListNode* reverseList1(ListNode *head){
		if (head == NULL || head->next == NULL) return head;
		ListNode *second = head->next;
		head->next = NULL;
		ListNode *reverse = reverseList1(second);
		second->next = head;
		return reverse;
	}

	//Reverse Linked List II
	ListNode* reverseBetween(ListNode* head, int m, int n){
		if (head == NULL || head->next == NULL) return head;
		int len = n - m;
		ListNode* foreHead = new ListNode(-1);
		foreHead->next = head;
		head = foreHead;
		ListNode *pre = head;
		while (m > 1){
			pre = pre->next;
			m--;
		}
		ListNode* curr = pre->next, *post = curr->next;
		if (len >= 1){
			while (len > 0 && post){
				ListNode *temp = post->next;
				post->next = curr;
				curr = post;
				post = temp;
				len--;
			}
			ListNode *temp = pre->next;
			pre->next = curr;
			temp->next = post; 
		}
		foreHead = head;
		head = head->next;
		delete foreHead;
		return head;
	}
};

void main(int argc, char *argv[]){
	ListNode *head1 = new ListNode(1);
	ListNode *tail = head1;
	ListNode *print = head1;
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
	ListNode *reverse = s.reverseList1(head1);
	cout << "The reversed list is: ";
	while (reverse != NULL){
		cout << reverse->val;
		reverse = reverse->next;
		if (reverse != NULL) cout << "->";
	}
	cout << endl;

	//Reverse Linked List II
	ListNode *head2 = new ListNode(1);
	ListNode *tail2 = head2;
	ListNode *n1 = new ListNode(2);
	tail2->next = n1;
	tail2 = tail2->next;
	ListNode *n2 = new ListNode(3);
	tail2->next = n2;
	tail2 = tail2->next;
	ListNode *n3 = new ListNode(4);
	tail2->next = n3;
	tail2 = tail2->next;
	ListNode *n4 = new ListNode(5);
	tail2->next = n4;
	tail2 = tail2->next;
	ListNode *n5 = new ListNode(6);
	tail2->next = n5;
	tail2 = tail2->next;
	ListNode *n6 = new ListNode(7);
	tail2->next = n6;
	tail2 = tail2->next;
	ListNode *n7 = new ListNode(8);
	tail2->next = n7;
	tail2 = tail2->next;
	ListNode *n8 = new ListNode(9);
	tail2->next = n8;
	tail2 = tail2->next;
	int m = 2;
	int n = 7;
	ListNode *res = s.reverseBetween(head2, m, n);
	cout << "The list after reversing the " << m << "th and " << n << "th nodes is: ";
	while (res){
		cout << res->val;
		res = res->next;
		if (res) cout << "->";
	}
	cout << endl;
	system("pause");
}