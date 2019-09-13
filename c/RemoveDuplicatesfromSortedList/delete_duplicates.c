/**
 * Author: Xiangyue Cai
 * Date: 2019-09-10
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

// runtime: 8ms
// memory usage: 7.7mb
ListNode* deleteDuplicates(ListNode* head){
    if(!head) return NULL;
    ListNode *res = head;
    while (head->next) {
        if(head->val == head->next->val) {
            ListNode *tmp = head->next->next;
            free(head->next);
            head->next = tmp;
        }
        else
            head = head->next;
        }
    return res;
}