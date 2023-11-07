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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;
        auto l = lowestCommonAncestor(root->left,p,q);
        auto r = lowestCommonAncestor(root->right,p,q);
        if(l!=NULL and r!= NULL) return root;
        else if(l==NULL and r== NULL) return NULL;
        else if(l!=NULL and r== NULL) return l; 
        else return r;
        
    }
};