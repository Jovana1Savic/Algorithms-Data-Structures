

/*
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

*/

    void topView(Node * root) {

        if (!root) return;

        map<int, Node*> m;
        // Level order traversal
        queue<pair<int,Node*>> q;
        q.push(pair<int, Node*>(0,root));
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int level = cur.first;
            if (m.find(level) == m.end())
                m.insert(pair<int, Node*>(level, cur.second));
            if (cur.second->left)
                q.push(pair<int, Node*>(cur.first-1, cur.second->left));
            if (cur.second->right)
                q.push(pair<int, Node*>(cur.first+1, cur.second->right));
        }

        for(auto it : m){
            cout << it.second->data << " ";
        }
    }

