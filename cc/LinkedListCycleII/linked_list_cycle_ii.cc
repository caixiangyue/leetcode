/**
 * Author: Lanqing Ye
 * Date: 2019-10-03
 */
/* 

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // Fun One 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
                break;
            }
        }
        if(!fast -> next || (fast -> next && !fast -> next -> next)){
            return nullptr;
        }
        
        int num = 1;
        fast = fast -> next;
        while(fast != slow){
            num ++;
            fast = fast -> next;
        }
        
        fast = head;
        slow = head;
        for(int i = 0;i < num;i++){
            fast = fast -> next;    
        }
        
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return fast;
    }
};

// Fun Two
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
                break;
        }
        if(!fast -> next || (fast -> next && !fast -> next -> next)){
            return nullptr;
        }
        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return fast;
            
        
    }
};
