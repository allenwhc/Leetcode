/*
*	Merge k Sorted Lists
*	Last Modified: 7/15/2015
*/

#include <vector>
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	ListNode *mergeKLists(vector<ListNode*>& lists){
		int num = lists.size();
		if (num == 0) return NULL;
		return helper(lists, 0, num - 1);
	}

	ListNode *helper(vector<ListNode*>& lists, int start, int end){
		if (start < end){
			int mid = (start + end) / 2;
			return mergeTwoLists(helper(lists, start, mid), helper(lists, mid + 1, end));
		}
		return lists[start];
	}

	ListNode *mergeTwoLists(ListNode *p, ListNode *q){
		ListNode *head = new ListNode(-1);
		ListNode *temp = head;
		while (p&&q){
			if (p->val < q->val){
				temp->next = p;
				temp = temp->next;
				p = p->next;
			}
			else{
				temp->next = q;
				temp = temp->next;
				q = q->next;
			}
		}
		if (p) temp->next = p;
		else temp->next = q;
		return head->next;
	}
};

void main(int argc, char *argv[]){
	//First linked list
	ListNode *head1 = new ListNode(1);
	ListNode *print1 = head1;
	ListNode *tail1 = head1;
	ListNode *n1_1 = new ListNode(5);
	tail1->next = n1_1;
	tail1 = tail1->next;
	ListNode *n1_2 = new ListNode(9);
	tail1->next = n1_2;
	tail1 = tail1->next;
	ListNode *n1_3 = new ListNode(13);
	tail1->next = n1_3;
	tail1 = tail1->next;

	//Second linked list
	ListNode *head2 = new ListNode(0);
	ListNode *print2 = head2;
	ListNode *tail2 = head2;
	ListNode *n2_1 = new ListNode(4);
	tail2->next = n2_1;
	tail2 = tail2->next;
	ListNode *n2_2 = new ListNode(8);
	tail2->next = n2_2;
	tail2 = tail2->next;
	ListNode *n2_3 = new ListNode(12);
	tail2->next = n2_3;
	tail2 = tail2->next;


	//Third linked list
	ListNode *head3 = new ListNode(3);
	ListNode *print3 = head3;
	ListNode *tail3 = head3;
	ListNode *n3_1 = new ListNode(7);
	tail3->next = n3_1;
	tail3 = tail3->next;
	ListNode *n3_2 = new ListNode(11);
	tail3->next = n3_2;
	tail3 = tail3->next;
	ListNode *n3_3 = new ListNode(15);
	tail3->next = n3_3;
	tail3 = tail3->next;

	//Fourth linked list
	ListNode *head4= new ListNode(2);
	ListNode *print4 = head4;
	ListNode *tail4 = head4;
	ListNode *n4_1 = new ListNode(6);
	tail4->next = n4_1;
	tail4 = tail4->next;
	ListNode *n4_2 = new ListNode(10);
	tail4->next = n4_2;
	tail4 = tail4->next;
	ListNode *n4_3 = new ListNode(14);
	tail4->next = n4_3;
	tail4 = tail4->next;

	vector<ListNode*> lists;
	lists.push_back(head1);
	lists.push_back(head2);
	lists.push_back(head3);
	lists.push_back(head4);

	vector<ListNode*> printList;
	printList.push_back(print1);
	printList.push_back(print2);
	printList.push_back(print3);
	printList.push_back(print4);

	for (int i = 0; i < printList.size(); i++){
		cout << "The ";
		cout << i + 1 << "th";
		cout << " sorted linked list is: ";
		while (printList[i]){
			cout << printList[i]->val;
			printList[i] = printList[i]->next;
			if (printList[i]) cout << "->";
		}
		cout << endl;
	}

	Solution s;
	ListNode *res = s.mergeKLists(lists);
	cout << "The merged list is: ";
	while (res){
		cout << res->val;
		res = res->next;
		if (res) cout << "->";
	}
	cout << endl;
	system("pause");
}