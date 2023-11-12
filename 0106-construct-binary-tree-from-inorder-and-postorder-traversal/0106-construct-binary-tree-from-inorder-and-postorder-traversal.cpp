/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inmpp;
        for(int i = 0; i < inorder.size(); i++){
            inmpp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inmpp);

        return root;  
    }
 
    TreeNode* buildTree(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, map<int,int>& inmpp) {
        if (instart > inend || poststart > postend) return NULL;    
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = inmpp[root->val];  
        int numsleft = inroot - instart;
        root->left = buildTree(inorder, instart, inroot - 1, postorder, poststart, poststart + numsleft - 1, inmpp);
        root->right = buildTree(inorder, inroot + 1, inend, postorder, poststart + numsleft, postend - 1, inmpp);    
            
        return root;    
    }
};
