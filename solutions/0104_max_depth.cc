/**
 * Author: Xiangyue Cai
 * Date: 2019-10-22
 */

// Example:

// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its depth = 3.

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        stack<pair<int, TreeNode*>> s;
        s.push({1, root});
        
        int depth = 0;
        int current_depth = 0;
        while (!s.empty()) {
            current_depth = s.top().first;
            root = s.top().second;
            s.pop();
            if (root != NULL) {
                depth = max(depth, current_depth);
                s.push({current_depth + 1, root->left});
                s.push({current_depth + 1, root->right});
            }
        }
        return depth;
    }
};