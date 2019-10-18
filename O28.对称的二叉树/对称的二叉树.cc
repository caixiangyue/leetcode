/**
 * Author: Lanqing Ye
 * Date: 2019-10-18
**/

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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return dfs(root -> left, root -> right);
    }
    
    bool dfs(TreeNode *p1, TreeNode *p2){
        if(p1 == NULL && p2 == NULL)    return true;
        if(p1 == NULL || p2 == NULL)    return false;
        return (p1 -> val == p2 -> val) && dfs(p1 -> left, p2 -> right) && dfs(p1 -> right, p2 -> left);
    }
};
