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
    bool isValidBST(TreeNode* root) {
        return isWithinBounds(root, INT_MAX, INT_MIN);
    }

private:
    bool isWithinBounds(TreeNode* root, int upperBound, int lowerBound) {
        if(!root)
            return true;
        if(!(root->val < upperBound && root->val > lowerBound))
            return false;
        
        return isWithinBounds(root->left, root->val, lowerBound) && 
               isWithinBounds(root->right, upperBound, root->val);
    }
};
