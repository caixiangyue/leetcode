/**
 * Author: Lanqing Ye
 * Date: 2019-10-03
 */
/* 

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4


Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *pHead = new ListNode(-1);
        while(head != NULL){
            ListNode *pNext = head -> next;
            ListNode *pNode = pHead;
            while(pNode -> next != nullptr && pNode -> next -> val <= head -> val){
                pNode = pNode -> next;
            }
            head -> next = pNode -> next;
            pNode -> next = head;
            head = pNext;
        }
        return pHead -> next;
    }
};

