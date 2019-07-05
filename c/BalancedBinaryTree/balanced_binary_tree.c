/**
 * Author: Xiangyue Cai
 * Date: 2019-07-05
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

static inline int
max(int a, int b)
{
    return a > b ? a : b;   
}

static inline int
height(TreeNode *node)
{
    if (!node)
        return 0;
    
    return max(height(node->left), height(node->right)) + 1;
}

bool
isBalanced(TreeNode* root){
    if (!root)
        return true;
    
    int left = height(root->left);
    int right = height(root->right);
    
    if (abs(left - right) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right))
        return true;
    return false;
}