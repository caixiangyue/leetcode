/**
 * Author: Lanqing Ye
 * Date: 2019-10-01
 */
/* 

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pNode = new ListNode(-1);
        pNode -> next = head;
        ListNode *fast = pNode;
        ListNode *slow = pNode;
        for(int i = 0;i < n;i++){
            fast = fast -> next;
        }
        while(fast -> next != nullptr ){
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return pNode -> next;
    }
};
