/**
 * Author: Lanqing Ye
 * Date: 2019-11-02
 */
 
 /* 
Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]

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
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)   return vector<int>();
        postorderTraversal(root -> left);
        postorderTraversal(root -> right);
        res.emplace_back(root -> val);
        return res;
    }
};


// Fun Two
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<int, TreeNode*>> sta;
        sta.push({0, root});
        while(sta.size()){
            auto tmp = sta.top();
            sta.pop();
            if(tmp.second ==  NULL) continue;
            if(tmp.first == 1)  res.emplace_back(tmp.second -> val);
            else{
                sta.push({1, tmp.second});
                sta.push({0, tmp.second -> right});
                sta.push({0, tmp.second -> left});
            }
        }
        return res;
    }
};

