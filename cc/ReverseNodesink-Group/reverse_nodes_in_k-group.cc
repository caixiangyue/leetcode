/**
 * Author: Lanqing Ye
 * Date: 2019-11-01 
 */
/* 
Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto node = head;
        int nodeNum = 0;
        while(node) nodeNum++, node = node -> next;
        if(nodeNum < k || k == 0) return head;
        auto pHead = new ListNode(-1);
        pHead -> next = head;
        auto pNode = pHead -> next;
        ListNode *pre = nullptr;
        ListNode *last;
        int times = k;
        bool flag = true;
        while(pNode){
            if(nodeNum >= k){
                times--;
                auto pNext = pNode -> next;
                pNode -> next = pre;
                pre = pNode;
                pNode = pNext;
                if(times == 0){
                    nodeNum -= k;
                    times = k;
                    if(flag)
                    {
                        pHead = pre, flag = false;
                    }else{
                        last -> next = pre;
                    }
                    while(pre -> next)  pre = pre -> next;
                    last = pre;
                    pre = pre -> next;
                }
                
            }else{
                pre = pNode;
                while(pNode)    pNode = pNode -> next;
            }
        }
        last -> next = pre;
        return pHead;
    }
};
 