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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int count = 1;
        while(!q.empty()){
            auto n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front().first;
                int baymax = q.front().second;
                q.pop();
                if(node->left){
                    if(node->left->val >= baymax){
                        count++;
                        q.push({node->left, node->left->val});
                    } else {
                        q.push({node->left, baymax});
                    }
                }
                if(node->right){
                    if(node->right->val >= baymax){
                        count++;
                        q.push({node->right, node->right->val});
                    } else {
                        q.push({node->right, baymax});
                    }
                }
            }
        }
        return count;
    }
};
