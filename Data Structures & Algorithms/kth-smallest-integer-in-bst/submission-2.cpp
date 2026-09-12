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
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return val;
    }

private:
    int val;

    void dfs(TreeNode* root, int& k) {
        if(!root)
            return;
        
        dfs(root->left, k);
        if(--k == 0)
            val = root->val;
        dfs(root->right, k);
    }
};
