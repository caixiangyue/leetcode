/**
 * Author: Xiangyue Cai
 * Date: 2019-07-16
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *res = NULL;
    struct ListNode *temp = NULL;
    res = temp = malloc(sizeof(struct ListNode));
    int carry = 0;
    while(l1 || l2)
    {
        int v1 = l1 == NULL ? 0 : l1->val;
        int v2 = l2 == NULL ? 0 : l2->val;
        
        int sum = v1 + v2 + carry;
        carry = sum / 10;
        struct ListNode *new = malloc(sizeof(struct ListNode));
        new->val = sum % 10;
        temp->next = new;
        temp = new;
        
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
    }
    if(carry)
    {
        struct ListNode *new = malloc(sizeof(struct ListNode));
        new->val = carry;
        temp->next = new;
        temp = new;
    }
        temp->next = NULL;
    return res->next;
}