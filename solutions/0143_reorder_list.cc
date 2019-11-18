/**
 * Author: Lanqing Ye
 * Date: 2019-10-01
 */
/* 

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.


Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL)    return ;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast -> next != nullptr && fast -> next -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        int flag = 0;
        if(fast -> next == nullptr){
            flag = 1;
        }
        ListNode *pre = nullptr;
        ListNode *pNode = slow -> next;
        ListNode *pNext = slow -> next;
        while(pNext -> next != nullptr){
            pNext = pNext -> next;
            pNode -> next = pre;
            pre = pNode;
            pNode = pNext;
        }
        pNode -> next = pre;
        pre = pNode;
        pNext = nullptr;
        pNode = nullptr;

        ListNode *res = head;
        ListNode *headNext = head;
        ListNode *preNext = pre;
        while(head -> next != nullptr && pre -> next != nullptr){
            headNext = headNext -> next;
            head -> next = pre;
            head = headNext;
            preNext = preNext -> next;
            pre -> next = head;
            pre = preNext;
        }
        if(flag == 1){ //odd
            headNext = headNext -> next;
            head -> next = pre;
            head = headNext;
            pre -> next = head;
            head -> next = nullptr;
        }else{ //even
            cout << "222" << endl;
            headNext = headNext -> next;
            head -> next = pre;
            head = headNext;
            pre -> next = nullptr;
        }
        return ;

    }
};
