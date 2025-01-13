#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void backtrack(TreeNode* node, string path, vector<string>& paths) {
        if (!node) return;
        path += to_string(node->val);
        if (!node->left && !node->right) {
            paths.push_back(path);
        } else {
            path += "->";
            backtrack(node->left, path, paths);
            backtrack(node->right, path, paths);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        backtrack(root, "", paths);
        return paths;
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    Solution solution;
    vector<string> result = solution.binaryTreePaths(root);
    for (const string& path : result) {
        cout << path << endl;
    }
    return 0;
}
