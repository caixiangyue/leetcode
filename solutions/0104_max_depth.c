/**
 * Author: Xiangyue Cai
 * Date: 2019-07-03
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

inline int max(int left, int right){
    if(left > right)
        return left;
    return right;
}

int maxDepth(struct TreeNode* root){
    if(!root)
        return 0;
    
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}