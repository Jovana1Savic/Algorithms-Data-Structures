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
    
    TreeNode* constructTree(vector<int>& arr, int begin, int end){
        
        if (begin < 0 || begin >= arr.size()) return NULL;
        if (begin > end) return NULL;
        if (end >= arr.size() || end < 0) return NULL;
        
        TreeNode* root = new TreeNode(arr[begin]);
        
        int mid  = -1;
        for (int i = begin + 1; i <= end; i++){
            if (arr[i] > arr[begin]){
                mid = i;
                break;
            }
        }
        
        if (mid == -1){
            root->left = constructTree(arr, begin + 1, end);
            root->right = NULL;
        }
        else {
            root->left = constructTree(arr, begin + 1, mid - 1);
            root->right = constructTree(arr, mid, end);
        }
            
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructTree(preorder, 0, preorder.size() - 1);
    }
};
