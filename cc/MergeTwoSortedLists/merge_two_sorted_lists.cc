/**
 * Author: Lanqing Ye
 * Date: 2019-10-02
 */
/* 

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/ 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Fun One 
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *pNode = head;
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2 -> val){
                pNode -> next = l1;
                pNode = pNode -> next;
                l1 = l1 -> next;
                
            }else{
                pNode -> next = l2;
                pNode = pNode -> next;
                l2 = l2 -> next;
            }
        }
        pNode -> next = l1 ? l1 : l2;
        return head -> next;
    }
};

// Fun Two:

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        if(l1 -> val < l2 -> val){
            l1 -> next = mergeTwoLists(l1 -> next,l2);
            return l1;
        }else{
            l2 -> next = mergeTwoLists(l1,l2 -> next);
            return l2;
        }
    }
};
