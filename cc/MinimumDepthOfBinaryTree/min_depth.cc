/**
 * Author: Xiangyue Cai
 * Date: 2019-09-03
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

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int min = 1;
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; ++i) {
                TreeNode *tmp = q.front();
                if(tmp->left == nullptr && tmp->right == nullptr)
                    return min;
                if(tmp->left != nullptr)
                    q.push(tmp->left);
                if(tmp->right != nullptr)
                    q.push(tmp->right);
                q.pop();
            }
            ++min;
        }
        return min;
    }
};