#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* sortedArrayToBSTHelper(const vector<int>& nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, right);
    
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}
void preOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main() {
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    TreeNode* root1 = sortedArrayToBST(nums1);
    preOrder(root1); 
    cout << endl;
    vector<int> nums2 = {1, 3};
    TreeNode* root2 = sortedArrayToBST(nums2);
    preOrder(root2);  
    return 0;
}
