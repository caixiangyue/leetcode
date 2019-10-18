/**
 * Author: Lanqing Ye
 * Date: 2019-10-16
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
    ListNode* deleteDuplication(ListNode* head) {
        if(head == NULL || head -> next == NULL)    return head;
        auto *pHead = new ListNode(-1);
        pHead -> next = head;
        auto *pNode = pHead;
        while(pNode -> next){
            ListNode *pNext = pNode -> next;
            while(pNext && pNode -> next -> val == pNext -> val)    pNext = pNext -> next;
            if(pNode -> next -> next == pNext)  pNode = pNode -> next;
            else    pNode -> next = pNext;
        }
        return pHead -> next;
        
    }
};
