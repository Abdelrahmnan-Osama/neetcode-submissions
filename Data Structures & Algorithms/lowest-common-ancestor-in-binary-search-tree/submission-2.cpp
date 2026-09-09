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
private:
    TreeNode* lca;

    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node)
            return false;
        
        bool is_in_curr_node = node->val == p->val || node->val == q->val;
        bool is_in_left_subtree = dfs(node->left, p, q);
        bool is_in_right_subtree = dfs(node->right, p, q);

        if(is_in_curr_node + is_in_left_subtree + is_in_right_subtree == 2)
            lca = node;

        return is_in_curr_node || is_in_left_subtree || is_in_right_subtree;
    }


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return lca;
    }
};
