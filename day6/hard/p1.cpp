#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};
Node* connect(Node* root) {
    if (!root) return nullptr;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            if (i < size - 1) {
                node->next = q.front();
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return root;
}
void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->val;
        if (node->next) {
            cout << " -> " << node->next->val;
        } else {
            cout << " -> NULL";
        }
        cout << " | ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    connect(root);
    printLevelOrder(root); 
    return 0;
}
