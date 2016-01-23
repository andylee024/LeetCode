/*
LeetCode Problem 92
Reverse Linked List II
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
            
            ListNode* newHead = new ListNode(-1);
            newHead->next = head;
            ListNode* prev = newHead;
            
            // get prev to position m-1
            for(auto i = 0 ; i < m-1 ; i++){prev = prev->next;}
            ListNode* const reversedPrev = prev;
            
            // prev at position m, cur at position m+1
            prev = prev->next;
            ListNode* cur = prev->next;
            
            for(auto i = m ; i < n ; i++){
                prev->next = cur->next;
                cur->next = reversedPrev->next;
                reversedPrev->next = cur;
                cur = prev->next;
            }
            return newHead->next;
    }
};
