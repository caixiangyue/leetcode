/**
 * Author: Xiangyue Cai
 * Date: 2019-07-02
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

static bool symmetric(TreeNode* p, TreeNode* q){
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    if (p->val == q->val)
        return symmetric(p->left, q->right) &&
            symmetric(p->right, q->left);
    return false;
}

bool isSymmetric(TreeNode* root){
    if (!root)
        return true;
    return symmetric(root, root);
}
