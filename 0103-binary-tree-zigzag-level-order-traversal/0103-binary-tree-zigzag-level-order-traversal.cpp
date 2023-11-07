#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if (root == nullptr) return vec;

        queue<TreeNode*> q;
        q.push(root);
        bool zigzag = false; // Flag to track the zigzag order.

        while (!q.empty()) {
            int size = q.size();
            vector<int> vec2(size);

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                int index = zigzag ? size - 1 - i : i; // Determine the index based on zigzag.

                vec2[index] = front->val;

                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }

            vec.push_back(vec2);
            zigzag = !zigzag; // Toggle the zigzag flag for the next level.
        }

        return vec;
    }
};
