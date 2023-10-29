#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
TreeNode *insert(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }

    if (value < root->val)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->val)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST
bool search(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->val == value)
    {
        return true;
    }
    else if (value < root->val)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}
void inorderTraversal(TreeNode* root){
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
int main()
{
    TreeNode *root = nullptr;

    // Insert nodes into the BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    int valueToSearch = 7;

    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    if (search(root, valueToSearch))
    {
        cout << valueToSearch << " found in the BST." << endl;
    }
    else
    {
        cout << valueToSearch << " not found in the BST." << endl;
    }

    return 0;
}
