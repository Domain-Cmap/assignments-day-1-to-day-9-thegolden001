#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* removeElements(ListNode* head, int val) {
    while (head && head->val == val) {
        head = head->next;
    }
    
    ListNode* current = head;
    while (current && current->next) {
        if (current->next->val == val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
}
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    ListNode* result = removeElements(head, 6);
    printList(result);
    return 0;
}
