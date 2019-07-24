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
inorderTraversal(TreeNode *root, int *returnSize){
    *returnSize = 0;
    if (!root)
        return NULL;
    int *res = malloc(sizeof(int) << 10);
    TreeNode *stack[1000];
    int count = 0;
    while (root || count > 0) {
        while (root){
            stack[count++] = root;
            root = root->left;
        }
        if (count > 0){
            root = stack[--count];
            res[(*returnSize)++] = root->val;
            root = root->right;
        }
    }
    return res;
}