#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> topView(Node* root) {
    vector<int> ans;
    // Using BFS to create a map
    map<int, int> mp; // {y, nodevalue}
    
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        auto frontpair = q.front();
        q.pop();
        
        int y = frontpair.second;
        if (mp.count(frontpair.second) == 0) {
            mp[frontpair.second] = frontpair.first->data;
        }
        
        if (frontpair.first->left) {
            q.push({frontpair.first->left, y - 1});
        }
        
        if (frontpair.first->right) {
            q.push({frontpair.first->right, y + 1});
        }
    }
    
    for (auto pair : mp) {
        ans.push_back(pair.second);
    }
    
    return ans;
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(7);
    root->right = new Node(9);
    root->left->right = new Node(11);
    root->left->right->right = new Node(13);
    root->left->right->right->right = new Node(17);

    vector<int> topViewResult = topView(root);

    cout << "Top View of the binary tree: ";
    for (int val : topViewResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
