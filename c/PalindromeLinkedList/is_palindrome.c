/**
 * Author: Xiangyue Cai
 * Date: 2019-09-24
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// runtime: 8ms
// memory usage: 10.9mb
typedef struct ListNode ListNode;

static inline ListNode*
reverse(ListNode *list, ListNode *mid)
{
    ListNode *pre = NULL;
    while(list != mid) {
        ListNode *tmp = list->next;
        list->next = pre;
        pre = list;
        list = tmp;
    }
    return pre;
}

bool
isPalindrome(ListNode *head)
{
    if (!head || !head->next) return true;
    
    ListNode *slow = head->next;
    ListNode *fast = head->next->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *pre = reverse(head, slow);
    if(fast) slow = slow->next;
    while(pre) {
        if (pre->val != slow->val) return false;
        pre = pre->next;
        slow = slow->next;
    }
    return true;
}