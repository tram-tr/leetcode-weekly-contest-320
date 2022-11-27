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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> answers;
        vector<int> path;
        traversal(root, path);
        int i = 0;
        sort(path.begin(), path.end());
        for (auto num : queries) {
            vector<int> ans(2, -1);
            int upper = upper_bound(path.begin(), path.end(), num) - (path.begin() + 1);
            int lower = lower_bound(path.begin(), path.end(), num) - path.begin();
            
            if (upper != -1)
                ans[0] = path[upper];
            if (lower != path.size())
                ans[1] = path[lower];
            
            answers.push_back(ans);
        }
        
        return answers;
    }
    
    void traversal(TreeNode* root, vector<int>&path) {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        if (root->left)
            traversal(root->left, path);
        
        if (root->right)
            traversal(root->right, path);
    }
    
    
    
};
