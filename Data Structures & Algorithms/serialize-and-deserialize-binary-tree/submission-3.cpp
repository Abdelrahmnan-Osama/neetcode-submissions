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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vec.clear();
        preorder_serialize(root);
        return join(vec, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        int start = 0;
        vector<string> node_values = split(data, ',');
        return preorder_deserialize(node_values, start);
    }

private:
    vector<string> vec;

    void preorder_serialize(TreeNode* node) {
        if(!node) {
            vec.push_back("N");
            return;
        }
        vec.push_back(to_string(node->val));

        preorder_serialize(node->left);
        preorder_serialize(node->right);
    }

    TreeNode* preorder_deserialize(const vector<string>& data, int& i) {
        if(data[i] == "N") {
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(data[i++]));

        node->left = preorder_deserialize(data, i);
        node->right = preorder_deserialize(data, i);

        return node;
    }

    vector<string> split(const string& s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string element;
        while(getline(ss, element, delim)) {
            elems.push_back(element);
        }
        return elems;
    }

    string join(const vector<string>& v, const string& delim) {
        string str = "";
        for(auto&& e : v) {
            str += e + delim;
        }
        str.pop_back();
        return str;
    }
};
