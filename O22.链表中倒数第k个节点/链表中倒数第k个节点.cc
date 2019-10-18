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
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        if(pListHead == NULL)   return pListHead;
        ListNode* pHead = new ListNode(-1);
        pHead -> next = pListHead;
        ListNode* fast = pHead -> next;
        ListNode* slow = pHead -> next;
        for(int i = 1; i < k; i ++){
            if(fast -> next == NULL)    return nullptr;
            fast = fast -> next;
        }
        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
};
