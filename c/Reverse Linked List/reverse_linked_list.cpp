/**
 * Author: Lanqing Ye
 * Date: 2019-08-24
 */
/* 
Example 1:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

*/ 


struct ListNode* reverseList(struct ListNode* head){
    if( head==NULL ){
        return head;
    }
    
    struct ListNode *p = head->next;
    head->next = NULL;
    
    while(p!=NULL){
       struct ListNode *temp = p->next;
       p->next = head;
       head = p;
       p = temp;
    }
    
    return head;
}
