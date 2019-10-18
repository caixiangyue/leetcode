/**
 * Author: Lanqing Ye
 * Date: 2019-10-17
**/

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
        if(head == NULL || head -> next == NULL)    return head;
        ListNode *pNode = head;
        ListNode *pre = nullptr;
        while(pNode){
            ListNode *pNext = pNode -> next;
            pNode -> next = pre;
            pre = pNode;
            pNode = pNext;
        }
        return pre;
    }
};
