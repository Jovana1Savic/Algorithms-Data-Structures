/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
#include <climits>
    bool isBST(Node* root, int min, int max){
        if (!root) return true;
        if (root->data >= max || root->data <= min) return false;
        return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
    }
	bool checkBST(Node* root) {
		return isBST(root, INT_MIN, INT_MAX);
	}
