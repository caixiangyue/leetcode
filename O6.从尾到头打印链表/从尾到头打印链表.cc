/**
 * Author: Lanqing Ye
 * Date: 2019-10-10
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
    vector<int> printListReversingly(ListNode* head) {
        vector<int> vec;
        ListNode *pNode = head;
        while(pNode){
            vec.emplace_back(pNode -> val);
            pNode = pNode -> next;
        }
        reverse(vec.begin(),vec.end());
        return vec;
        //return vector<int>(vec.rbegin(), vec.rend()); 
    }
};

