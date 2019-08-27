/**
 * Author: Xiangyue Cai
 * Date: 2019-08-27
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    struct ListNode *head , *merged, *tmp;
    head = merged = tmp = NULL;
    for (;;) {
        if (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tmp= l1;
                l1 = l1->next;
            }
            else {
                tmp = l2;
                l2 = l2->next;
            }
            if (merged) merged->next = tmp;
            merged = tmp;
            if (!head) head = merged;
        }
        else if (l1 == NULL && l2 != NULL) {
            merged->next = l2;
            break;
        }
        else if(l1 != NULL && l2 == NULL) {
            merged->next = l1;
            break;
        }
        else
            break;
                    
    }
    
    return head;
}