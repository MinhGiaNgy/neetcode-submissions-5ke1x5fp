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
    void dfs(TreeNode* first, TreeNode* second, bool& ans){
        if(!first && !second){
           return;
        } 
        if(!first || !second) {
            ans = false;
            return;
        }
        if(first->val != second->val){
            ans = false;
            return;
        } 
        dfs(first->left, second->left,ans);
        dfs(first->right, second->right,ans); 
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        dfs(p, q, ans);
        return ans;

    }
};
