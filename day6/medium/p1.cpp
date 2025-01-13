#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* buildTreeHelper(const vector<int>& preorder, int& preorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& inorderMap) {
    if (inorderStart > inorderEnd) return nullptr;
    int rootVal = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(rootVal);
    int rootIndexInInorder = inorderMap[rootVal];
    root->left = buildTreeHelper(preorder, preorderIndex, inorderStart, rootIndexInInorder - 1, inorderMap);
    root->right = buildTreeHelper(preorder, preorderIndex, rootIndexInInorder + 1, inorderEnd, inorderMap);
    return root;
}
TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    int preorderIndex = 0;
    return buildTreeHelper(preorder, preorderIndex, 0, inorder.size() - 1, inorderMap);
}
void printTree(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
}
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = buildTree(preorder, inorder);
    printTree(root); 
    return 0;
}
