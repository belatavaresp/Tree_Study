#include <iostream>

using namespace std;

// Define the binary tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Define the binary tree class
class BinaryTree {
private:
    TreeNode* root;

    // Recursive helper functions for the traversal methods
    void inOrderHelper(TreeNode* node) {
        if (node == nullptr) return;
        inOrderHelper(node->left);
        cout << node->val << " ";
        inOrderHelper(node->right);
    }

    void preOrderHelper(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->val << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }

    void postOrderHelper(TreeNode* node) {
        if (node == nullptr) return;
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        cout << node->val << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    // Method for inserting a node into the binary tree
    void insert(int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return;
        }

        TreeNode* cur = root;
        while (true) {
            if (val < cur->val) {
                if (cur->left == nullptr) {
                    cur->left = new TreeNode(val);
                    return;
                }
                cur = cur->left;
            } else {
                if (cur->right == nullptr) {
                    cur->right = new TreeNode(val);
                    return;
                }
                cur = cur->right;
            }
        }
    }

    // Methods for the three different traversal types
    void inOrderTraversal() {
        inOrderHelper(root);
        cout << endl;
    }

    void preOrderTraversal() {
        preOrderHelper(root);
        cout << endl;
    }

    void postOrderTraversal() {
        postOrderHelper(root);
        cout << endl;
    }
};

// Example usage
int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "In-order traversal: ";
    tree.inOrderTraversal();

    cout << "Pre-order traversal: ";
    tree.preOrderTraversal();

    cout << "Post-order traversal: ";
    tree.postOrderTraversal();

    return 0;
}
