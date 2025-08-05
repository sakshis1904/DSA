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
        int cnt = 0;
        int res = 0;
        inorder(root, k, cnt, res);
        return res;
    }

    void inorder(TreeNode* node, int k, int& cnt, int& res){
        if (node == nullptr || cnt >= k) return;
        inorder(node->left, k, cnt, res);
        cnt++;
        if(cnt == k){
            res = node->val;
            return;
        }
        inorder(node->right, k, cnt, res);
    }
};