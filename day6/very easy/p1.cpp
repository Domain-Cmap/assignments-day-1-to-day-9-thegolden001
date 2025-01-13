#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void inorderRecursive(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    inorderRecursive(root->left, result);
    result.push_back(root->val);
    inorderRecursive(root->right, result);
}
vector<int> inorderTraversalRecursive(TreeNode* root) {
    vector<int> result;
    inorderRecursive(root, result);
    return result;
}
vector<int> inorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* current = root;
    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        result.push_back(current->val);
        current = current->right;
    }

    return result;
}
TreeNode* buildExampleTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}
int main() {
    TreeNode* root = buildExampleTree();
    cout << "Recursive Inorder Traversal: ";
    vector<int> recursiveResult = inorderTraversalRecursive(root);
    for (int val : recursiveResult) {
        cout << val << " ";
    }
    cout << endl;
    cout << "Iterative Inorder Traversal: ";
    vector<int> iterativeResult = inorderTraversalIterative(root);
    for (int val : iterativeResult) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
