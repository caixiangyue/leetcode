/**
 * Author: Xiangyue Cai
 * Date: 2019-10-21
 */

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \      \
// 7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// runtime: 12ms beats 75.78%
// memory usage: 19.8mb beats 93.75%
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        stack<TreeNode*> s;
        int temp = 0;
        while(root || !s.empty()) {
            if (root == NULL) {
                root = s.top();
                s.pop();
                if(root->right != NULL) {
                    TreeNode *t = root->left;
                    while(t) {
                        temp -= t->val;
                        if (t->right==NULL)
                            t = t->left;
                        else
                            t = t->right;
                    }
                }
                root = root->right;
                continue;
            }
        
            s.push(root);
            temp += root->val;
            
            if (root->left == NULL && root->right == NULL) {
                if (temp == sum) return true;
            }
            
            root = root->left;
        }
        return false;
    }
};