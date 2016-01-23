/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Leet Code #206 
Reverse a Linked LIst
*/

class Solution {
public:
    
    // iterative solution
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* next = curr->next; 
            curr->next = prev; 
            prev = curr;  
            curr = next;
        }
        head = prev;
        return head;
    }
    
    // recursive solution
    /* reverses list, but gives you tail of new reversed list */
    ListNode* reverseList(ListNode* head) { 
        if (!head) return NULL;
        if (!head->next) return head; 
        ListNode* p;
        p = reverseList(head->next);
        p->next = head;
        return head;
    }
};
