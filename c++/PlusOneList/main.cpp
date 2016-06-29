/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
    ListNode* reverseList(ListNode* head){
        ListNode *preHead = new ListNode(-1);
        preHead->next = head;
        head = preHead;
        
        ListNode* curr= head->next;
        while(curr && curr->next){
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = head->next;
            head->next = next;
        }
        head = head->next;
        delete preHead;
        return head;
    }
public:
    ListNode* plusOne(ListNode* head) {
        if(!head) return NULL;
        head = reverseList(head);
        int carry = 1;
        ListNode* curr = head;
        ListNode* newHead = new ListNode(0);
        ListNode* p = newHead;
        while(curr){
            carry += curr->val;
            p->next = new ListNode(carry % 10);
            p = p->next;
            carry /= 10;
            curr = curr->next;
        }
        cout << carry << endl;
        if(carry != 0){
            p->next = new ListNode(carry%10);
        }
        return reverseList(newHead->next);
    }
};