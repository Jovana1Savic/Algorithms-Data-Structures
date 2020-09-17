#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;

class Node;

class Node {
public:
    int key;
    Node* parent;
    std::vector<Node*> children;

    Node() {
        this->parent = NULL;
    }

    void setParent(Node* theParent) {
        parent = theParent;
        parent->children.push_back(this);
    }
};

int maxHeight(std::vector<Node>& tree, int root) {

    if (tree.empty()) return 0;

    stack<Node*> s;
    stack<int> levels;
  
    s.push(&tree[root]);
    levels.push(0);

    int maxLevel = -1;

    while (!s.empty()) {
        Node* n = s.top();
        int level = levels.top();

        s.pop(); levels.pop();

        if (level > maxLevel)
            maxLevel = level;

        for (auto it = n->children.begin(); it != n->children.end(); ++it) {
            s.push(*it);
            levels.push(level + 1);
        }
    }

    return maxLevel + 1;
}

int main_with_large_stack_space() {
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;

    std::vector<Node> nodes;
    nodes.resize(n);
    int root = -1;
    for (int child_index = 0; child_index < n; child_index++) {
        int parent_index;
        std::cin >> parent_index;
        if (parent_index >= 0)
            nodes[child_index].setParent(&nodes[parent_index]);
        else
            root = child_index;
        nodes[child_index].key = child_index;
    }

    // Replace this code with a faster implementation
    std::cout << maxHeight(nodes, root) << std::endl;
    return 0;
}

int main(int argc, char** argv)
{
#if defined(__unix__) || defined(__APPLE__)
    // Allow larger stack space
    const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                std::cerr << "setrlimit returned result = " << result << std::endl;
            }
        }
    }

#endif
    return main_with_large_stack_space();
}
