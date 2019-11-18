/**
 * Author: Lanqing Ye
 * Date: 2019-09-23 
 */
/* 
Example 1:
Input: 1->2
Output: false


Example 2:
Input: 1->2->2->1
Output: true

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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        
        //find the mid of List
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        while( fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //reserve
        ListNode *pre = nullptr;
        ListNode *pNode = head;
        while(pNode != slow){
            ListNode *pNext = pNode->next;
            pNode->next = pre;
            pre = pNode;
            pNode = pNext;
        }
        // odd or even ?
        if(fast != NULL){
            slow = slow->next;
        }
        
        while(pre!=NULL){
            if(pre->val != slow->val){
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return true;
        
    }
};