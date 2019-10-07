/**
 * Author: Lanqing Ye
 * Date: 2019-10-01
 */
/* 

Example 1:
Input: 1->1->2
Output: 1->2


Example 2:
Input: 1->1->2->3->3
Output: 1->2->3

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)    return head;
        ListNode *pHead = head;
        ListNode *pNode = head;
        ListNode *pNext = head;
        while(pNext -> next != nullptr){
            pNext = pNext -> next;
            if(pNode -> val != pNext -> val){
                pNode -> next = pNext;
                pNode = pNode -> next;
            }
        }
        pNode -> next = nullptr;
        return pHead;
    }
};
