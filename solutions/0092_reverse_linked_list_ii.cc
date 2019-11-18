/**
 * Author: Lanqing Ye
 * Date: 2019-10-01
 */
/* 

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || n == m)  return head;
        ListNode *pHead = new ListNode(-1);
        pHead -> next = head;
        ListNode *pre = pHead;
        ListNode *pFlag = pre;
        int flag = 0;
        while(flag < m){
            if(flag == m - 1){
                pFlag = pre;
            }
            pre = pre -> next;
            flag++;
        }
        ListNode *pEnd = pre;
        ListNode *pNode = pre -> next;
        ListNode *pNext = pre -> next;
        while(flag >= m && flag < n){
            pNext = pNext -> next;
            pNode -> next = pre;
            pre = pNode;
            pNode = pNext;
            flag++;
        }
        pEnd -> next = pNode;
        pFlag -> next = pre;
        return pHead -> next;
        
    }
};
