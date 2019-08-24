/**
 * Author: Xiangyue Cai
 * Date: 2019-08-24
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (slow != NULL && slow->next != NULL) {
        slow = slow->next->next;
        fast = fast->next;
        if (slow == fast)
            return true;
    }
    return false;
}