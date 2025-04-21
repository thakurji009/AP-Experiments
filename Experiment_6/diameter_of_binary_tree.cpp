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
        int dfs(TreeNode* root, int& n){
            if(root == nullptr) return 0;
            int ml = dfs(root->left, n);
            int mr = dfs(root->right, n);
            n = max(n, ml+mr);
            return 1+max(ml,mr);
        }
        int diameterOfBinaryTree(TreeNode* root) {
            int ans = 0;
            dfs(root, ans);
            return ans;
        }
    };