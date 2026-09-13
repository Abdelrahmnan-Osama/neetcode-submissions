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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_index = 0;
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            inorder_indecies[inorder[i]] = i;
        }
        return buildSubtree(0, n - 1, preorder, inorder);
    }

private:
    int preorder_index;
    unordered_map<int, int> inorder_indecies;

    TreeNode* buildSubtree(int left, int right, vector<int>& preorder,      vector<int>& inorder) {
        if(left > right)
            return nullptr;
        
        int val = preorder[preorder_index];
        int inorder_index = inorder_indecies[val];
        TreeNode* node = new TreeNode(val);
        preorder_index++;

        node->left = buildSubtree(left, inorder_index-1, preorder, inorder);
        node->right = buildSubtree(inorder_index+1, right, preorder, inorder);

        return node;
    }
};
