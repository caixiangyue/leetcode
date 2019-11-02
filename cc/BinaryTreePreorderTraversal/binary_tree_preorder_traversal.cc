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

Output: [1,2,3]

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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)    return vector<int>();
        res.emplace_back(root -> val);
        preorderTraversal(root -> left);
        preorderTraversal(root -> right);
        return res;
    }
};


// Fun Two
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<int, TreeNode*>> sta;
        sta.push({0, root});
        while(sta.size()){
            auto tmp = sta.top();
            sta.pop();
            if(tmp.second == NULL)  continue;
            if(tmp.first == 1)  res.emplace_back(tmp.second -> val);
            else{
                sta.push({0, tmp.second -> right});
                sta.push({0, tmp.second -> left});
                sta.push({1, tmp.second});
            }
        }
        return res;
    }
};
