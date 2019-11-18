/**
 * Author: Lanqing Ye
 * Date: 2019-10-01
 */
/* 

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == nullptr) return head;
        ListNode *pre = nullptr;
        ListNode *pNode = head;
        ListNode *pNext = head;
        while(pNext -> next != nullptr){
            pNext = pNext -> next;
            pNode -> next = pre;
            pre = pNode;
            pNode = pNext;
        }
        pNode -> next = pre;
        pre = pNode;
        return pre;
    }
};
