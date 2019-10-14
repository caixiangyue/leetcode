/**
 * Author: Lanqing Ye
 * Date: 2019-10-10
 */
 
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
    unordered_map<int,int> hash_map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        for(int i = 0; i < len ; i++){
            hash_map[inorder[i]] = i;
        }
        return dfs(preorder,inorder,0,len-1,0,len-1);
    }
    
    TreeNode* dfs(vector<int>& preorder,vector<int>& inorder,int pl,int pr,int il,int ir){
        if(pl > pr || il > ir)
            return NULL;
        int k = hash_map[preorder[pl]];
        TreeNode* root = new TreeNode(preorder[pl]);
        root -> left = dfs(preorder,inorder,pl+1,pl+k-il,il,k-1);
        root -> right = dfs(preorder,inorder,pl+k-il+1,pr,k+1,ir);
        return root;
    }
    
};
