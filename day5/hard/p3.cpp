#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    priority_queue<ListNode*, vector<ListNode*>, greater<ListNode*>> pq;
    for (int i = 0; i < k; ++i) {
        if (lists[i] != nullptr) {
            pq.push(lists[i]);
        }
    }
    ListNode* head = new ListNode(); 
    ListNode* tail = head;

    while (!pq.empty()) {
        ListNode* current = pq.top();
        pq.pop();

        tail->next = current;
        tail = tail->next;

        if (current->next != nullptr) {
            pq.push(current->next);
        }
    }
    return head->next;
}
ListNode* createLinkedList(const vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int num : nums) {
        ListNode* newNode = new ListNode(num);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> lists = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> listNodes;

    for (const auto& nums : lists) {
        listNodes.push_back(createLinkedList(nums));
    }
    ListNode* mergedList = mergeKLists(listNodes);
    printLinkedList(mergedList);
    ListNode* temp;
    while (mergedList != nullptr) {
        temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }
    for (ListNode* list : listNodes) {
        while (list != nullptr) {
            temp = list;
            list = list->next;
            delete temp;
        }
    }
    return 0;
}