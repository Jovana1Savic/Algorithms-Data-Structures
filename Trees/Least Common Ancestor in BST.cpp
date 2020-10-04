#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {

        if (!root) return nullptr;

		Node* cur = root;
        while (cur){

            if (cur->data == v1 || cur->data == v2)
                return cur;

            bool left1 = true, left2 = true;
            if (cur->data < v1) left1 = false;
            if (cur->data < v2) left2 = false;

            if (left1 != left2) return cur;

            if (left1){
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }

        return nullptr;
    }

}; //End of Solution
