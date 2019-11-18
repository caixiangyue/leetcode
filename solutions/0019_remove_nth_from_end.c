/**
 * Author: Xiangyue Cai
 * Date: 2019-08-26
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    if (head == NULL)
        return NULL;

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    while (fast != NULL && n > 0) {
        fast = fast->next;
        --n;
    }
    
    if (fast == NULL)
        return head->next;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    if (slow != NULL && slow->next != NULL)
        slow->next = slow->next->next;
    
    return head;   
}