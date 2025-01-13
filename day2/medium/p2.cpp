#include <iostream>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(Node* root) {
    if (!root) return;
    Node* level_start = root;
    while (level_start->left) {
        Node* current = level_start;
        while (current) {
            current->left->next = current->right;  
            if (current->next) {
                current->right->next = current->next->left;  
            }
            current = current->next;  
        }
        level_start = level_start->left;  
    }
}
void printTree(Node* root) {
    Node* level_start = root;
    while (level_start) {
        Node* current = level_start;
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << "# ";  
        level_start = level_start->left;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    connect(root);
    printTree(root);  
    return 0;
}
