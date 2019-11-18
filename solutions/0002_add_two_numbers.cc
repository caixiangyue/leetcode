/**
 * Author: Lanqing Ye
 * Date: 2019-09-24
 */
/* 
Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int flag = 0;
        while(l1||l2||flag){
            flag = (l1?l1->val:0)+(l2?l2->val:0)+flag;
            p->next = new ListNode(flag%10);
            p = p->next;
            flag = flag/10;
            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        ListNode *res = head->next;
        delete head;
        return res;
    }
};
