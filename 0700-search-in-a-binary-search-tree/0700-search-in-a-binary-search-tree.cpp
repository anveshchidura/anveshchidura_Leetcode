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
    TreeNode* Preorder(TreeNode* &root){
        if(root == NULL) return nullptr;
        
        // Assuming TreeNode has left and right members
        Preorder(root->left);
        Preorder(root->right);
        return root;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr; 

        if(root->val < val) {
            return searchBST(root->right, val);
        } else if(root->val > val) {
            return searchBST(root->left, val);
        } else {

            return Preorder(root);
        }
    }
};
