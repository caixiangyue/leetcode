/**
 * Author: Lanqing Ye
 * Date: 2019-11-01 
 */
/* 

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.

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
    ListNode* swapPairs(ListNode* head) {
        auto node = head;
        int nodeNum = 0;
        while(node) node = node -> next, nodeNum++;
        if(head == NULL || head -> next == NULL)    return head;
        ListNode *pHead = new ListNode(-1);
        pHead -> next = head;
        auto pNode = pHead -> next;
        ListNode *pre = nullptr;
        ListNode *last;
        bool is_head = true;
        int times = 2;
        while(pNode){
            if(nodeNum >= 2){
                times--;
                auto pNext = pNode -> next;
                pNode -> next = pre;
                pre = pNode;
                pNode = pNext;
                if(times == 0){
                    nodeNum -= 2;
                    times = 2;
                    if(is_head) pHead = pre, is_head = false;
                    else{
                        last -> next = pre;
                    }
                    while(pre -> next)  pre = pre -> next;
                    last = pre;
                    pre = pre -> next;
                }
                
            }else{
                pre = pNode;
                pNode = pNode -> next;
            }
        }
        last -> next = pre;
        return pHead;
    }
};
