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
        
        // You might want to do something with the current node, or return it
        // For now, let's return the current node
        return root;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr; // Added null check for the base case

        if(root->val < val) {
            return searchBST(root->right, val);
        } else if(root->val > val) {
            return searchBST(root->left, val);
        } else {
            // If the current node's value is equal to the target value, 
            // you may want to return the node itself or do some other operation.
            // For now, I'm returning the result of Preorder function.
            return Preorder(root);
        }
    }
};
