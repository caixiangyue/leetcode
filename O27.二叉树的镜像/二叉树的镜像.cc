/**
 * Author: Lanqing Ye
 * Date: 2019-10-17
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
    void mirror(TreeNode* root) {
        if(root){
            TreeNode *tmp = root -> left;
            root -> left = root -> right;
            root -> right = tmp;
            mirror(root -> left);
            mirror(root -> right);
        }else   return;
    }
};
