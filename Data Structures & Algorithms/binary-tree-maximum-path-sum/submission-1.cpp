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
    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return maxSum;
    }

private:
    int maxSum = INT_MIN;
    
    int maxPathSumHelper(TreeNode* root) {
        if(!root)
            return 0;

        int maxLeftSum = max(maxPathSumHelper(root->left), 0);
        int maxRightSum = max(maxPathSumHelper(root->right), 0);

        maxSum = max(maxSum, root->val + maxLeftSum + maxRightSum);

        return root->val + max(maxLeftSum, maxRightSum);
    }
};
