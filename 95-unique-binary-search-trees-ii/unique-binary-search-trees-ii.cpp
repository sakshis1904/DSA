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
    vector<TreeNode*> build(int l, int r) {
        if (l > r) return {nullptr};
        vector<TreeNode*> res;
        for (int i = l; i <= r; i++) {
            auto left = build(l, i - 1);
            auto right = build(i + 1, r);
            for (auto L : left) {
                for (auto R : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = L;
                    root->right = R;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};
