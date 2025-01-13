#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* pre = &dummy;
    ListNode* curr = head;

    while (true) {
        ListNode* group_start = pre->next;
        ListNode* group_end = pre;
        for (int i = 0; i < k; ++i) {
            group_end = group_end->next;
            if (!group_end) return dummy.next;
        }

        ListNode* next_group = group_end->next;
        ListNode* prev = next_group;
        curr = group_start;
        while (curr != next_group) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        pre->next = group_end;
        pre = group_start;
    }
}
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 2;
    head = reverseKGroup(head, k);
    printList(head); 
    return 0;
}
