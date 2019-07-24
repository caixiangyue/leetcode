/**
 * Author: Xiangyue Cai
 * Date: 2019-07-24
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct TreeNode TreeNode;

int*
preorderTraversal(TreeNode *root, int *returnSize){
    *returnSize = 0;
    if (!root)
        return NULL;
    int *res = malloc(sizeof(int) << 10);
    TreeNode *stack[1000];
    int count = 0;
    while (root || count > 0) {
        while (root){
            res[(*returnSize)++] = root->val;
            stack[count++] = root;
            root = root->left;
        }
        if (count > 0)
            root = stack[--count]->right;
    }
    return res;
}