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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *pHead = new ListNode(-1);
        ListNode *res = pHead;
        while(l1 && l2){
            if(l1 -> val <= l2 -> val){
                res -> next = l1;
                l1 = l1 -> next;
            }else{
                res -> next = l2;
                l2 = l2 -> next;
            }
            res = res -> next;
        }
        while(l1){
            res -> next = l1;
            l1 = l1 -> next;
            res = res -> next;
        }
        while(l2){
            res -> next = l2;
            l2 = l2 -> next;
            res = res -> next;
        }
        res -> next = nullptr;
        res = res -> next;
        return pHead -> next;
    }  
};
