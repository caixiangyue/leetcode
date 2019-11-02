/**
 * Author: Lanqing Ye
 * Date: 2019-11-02
 */
 
 /* 
 
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
   
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        level(root, 0);
        return res;
    }
    void level(TreeNode* root, int dep){
        if(!root)   return;
        if(dep >= res.size()) res.emplace_back(vector<int>{});
        res[dep].emplace_back(root -> val);
        level(root -> left, dep + 1);
        level(root -> right, dep + 1);
    }
};

// Fun Two
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)   return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            vector<int> vec;
            int width=q.size();
            for(int i=0;i<width;i++){
                auto tmp = q.front();
                vec.push_back(tmp -> val);
                q.pop();
                if(tmp ->left) q.push(tmp -> left);
                if(tmp ->right) q.push(tmp -> right);
            }
            res.push_back(vec);
        }
    return res;
    }
};

