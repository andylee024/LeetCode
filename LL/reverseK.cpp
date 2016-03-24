// Leet Code 25 - Reverse Nodes in k-Group

/*
Notes:
This was a very complicated problem and the below solution is someone else's. 
I have annotated the solution with key points to remember. 

The basic algorithm has the following steps.
1. Check if next k nodes exist
2. If they exist, then reverse next k nodes.
3. Update markers so that you work on next part of list on next iteration.

A few very important concepts to remember. 
1. The reversal algorithm is extremely elegant in that it avoids initializing new memory. Instead, the solution updates pointers accordingly. 

Draw out the picture and work through some iterations to really understand algo.
a. tmp represents ith node.
b. move node 1 to point to i+1
c. move ith node to point to prev->next (front of list on previous iteration)
d. let prev->next point to tmp so tmp is now in the front

2. return head->next
Note that head gets initialized to prev in the beginning. This means that
whatever prev gets pointed to, head also points to. However, once prev gets 
reinitialized to another item, head DOES NOT get reinitialized to this new item. THis is because head = original prev and not new prev. 

It turns out by the algorithm's design that after 1st iteration prev->next is exactly the item we want. Once we have the item we want, we reinitialize prev. 

*/

/*
CORRECT SOLUTION: 
courtesy of http://gongxuns.blogspot.com/2012/12/leetcode-reverse-nodes-in-k-group.html
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // edge cases 
        if (!head || k<=1 || !head->next) return head;
        
        // initialization
        ListNode* prev = new ListNode(0);
        prev->next = head;
        head = prev;
        ListNode* cur = prev->next;
        
        // algorithm
        while (cur){
            int counter = k;
            
            // check if k nodes can be reversed 
            while (counter > 1 && cur){
                cur = cur->next;
                counter--;
            }
            
            // reverse current k nodes
            if (cur){
                cur = prev->next;
                counter = k;
                while (counter > 1){
                    ListNode* tmp = cur->next;
                    cur->next = tmp->next;
                    tmp->next = prev->next;
                    prev->next = tmp;
                    counter--;
                }
                
                // set new markers 
                prev = cur;
                cur = prev->next;

            }
        }
        return head->next;
    }
};

/*
* MY SOLUTION 
*/


class Solution {
public:
    
    // Given (head, k), if list is at least length k returns kth element from head (inclusive). Returns null otherwise. 
    ListNode* checkReversible(ListNode* head, int k){  
        if(!head) 
            return nullptr;
            
        ListNode* cur = head;
        for (int i=1; i<k; i++){
            if (!cur->next)
                return nullptr;
            else
                cur = cur->next;
        }
        return cur;
    }
    
    // Given (head, k) reverses list up to k nodes and links last element of reversed list to end
    ListNode* reverseK(ListNode* head, ListNode* end, int k){ 
        ListNode *p1, *p2, *tmp;
        p1 = end;
        p2 = head;
        
        for (int i=1; i<k; i++){
            tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        p2->next = p1;
        return p2;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *end, *root;
        end = checkReversible(head,k);
        
        // list length < k  
        if (!end || k==1) // fix k==1 to be more general
            return head;
        
        else{
            // reverse 1st time 
            root = reverseK(head, end->next, k);
            head = end->next;
            
            while(head){
                end = checkReversible(head,k);
                if (end){ // list can still be reversed
                    reverseK(head,end->next,k);
                    head = end->next;
                }
            }
        }
        return root;
    }
};
