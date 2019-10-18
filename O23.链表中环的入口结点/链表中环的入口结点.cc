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
    ListNode *entryNodeOfLoop(ListNode *head) {
        if(head == NULL || head -> next == NULL ) return nullptr;
        ListNode *pHead = new ListNode(-1);
        pHead -> next = head;
        ListNode *fast = pHead -> next;
        ListNode *slow = pHead -> next;
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)    break;
        }
        if(fast -> next == NULL || fast -> next -> next == NULL)    return nullptr;
        slow = pHead -> next;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return fast;
    }
};
