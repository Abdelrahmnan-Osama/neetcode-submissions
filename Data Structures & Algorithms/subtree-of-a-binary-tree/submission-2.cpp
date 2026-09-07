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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSameTree(root, subRoot))
            return true;
        
        bool isLeftSubtree = isSubtree(root->left, subRoot);
        bool isRightSubtree = isSubtree(root->right, subRoot);

        return isLeftSubtree || isRightSubtree;
    }

private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;

        if(p->val != q->val)
            return false;
        
        bool sameLeft = isSameTree(p->left, q->left);
        bool sameRight = isSameTree(p->right, q->right);

        return sameLeft && sameRight;
    }
};
