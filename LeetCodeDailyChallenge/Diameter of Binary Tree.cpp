/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int max(int a, int b){
        if (a > b) return a;
        return b;
    }
    
    int height(TreeNode* root, int& ans){
        
        if (!root) return 0;
        
        int left_height = height(root->left, ans);
        int right_height = height(root->right, ans);
        
        ans = max(ans, 1 + left_height + right_height);
        
        return 1 + max(left_height, right_height);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans = 0;
        int h = height(root, ans);
        if (ans == 0) return 0;
        return ans - 1;
    }
};
