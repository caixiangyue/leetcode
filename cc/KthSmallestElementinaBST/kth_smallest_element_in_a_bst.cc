/**
 * Author: Lanqing Ye
 * Date: 2019-11-02
 */
 
 /* 
 
Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
?  2
Output: 1


Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

*/ 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Fun One
class Solution {
public:
    vector<int> vec;
    int kthSmallest(TreeNode* root, int k) {
        Order(root);
        return vec[k - 1];
    }
    
    void Order(TreeNode* root){
        if(root == NULL) return;
        Order(root -> left);
        vec.emplace_back(root -> val);
        Order(root -> right);
        return;
    }
};

// Fun Two
class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        stack<pair<int, TreeNode*>> sta;
        sta.push({0, root});
        while(sta.size()){
            auto tmp = sta.top();
            sta.pop();
            if(tmp.second == NULL)  continue;
            if(tmp.first == 1)  vec.emplace_back(tmp.second -> val);
            else{
                sta.push({0, tmp.second -> right});
                sta.push({1, tmp.second});
                sta.push({0, tmp.second -> left});
            }
        }
        return vec[k - 1];
    }
};
 