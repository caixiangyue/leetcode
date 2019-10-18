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
    bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot1 == NULL || pRoot2 == NULL)    return false;
        if(isSame(pRoot1, pRoot2))  return true;
        return hasSubtree(pRoot1 -> left, pRoot2) || hasSubtree(pRoot1 -> right, pRoot2);
    }
    
    bool isSame(TreeNode* p1, TreeNode* p2){
        if(p2 == NULL)  return true;
        if(p1 == NULL || p1 -> val != p2 -> val)    return false;
        return isSame(p1 -> left, p2 -> left) && isSame(p1 -> right, p2 -> right);
    }
    
};
