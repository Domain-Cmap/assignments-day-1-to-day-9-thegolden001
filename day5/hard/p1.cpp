#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    vector<vector<int>> groupGraph(m, vector<int>());
    vector<vector<int>> itemGraph(n, vector<int>());
    vector<int> groupIndegree(m, 0);
    vector<int> itemIndegree(n, 0);
    for (int i = 0; i < n; ++i) {
        if (group[i] != -1) {
            for (int j : beforeItems[i]) {
                if (group[j] != -1 && group[j] != group[i]) {
                    groupGraph[group[j]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }
        for (int j : beforeItems[i]) {
            itemGraph[j].push_back(i);
            itemIndegree[i]++;
        }
    }
    vector<int> groupOrder;
    queue<int> groupQueue;
    for (int i = 0; i < m; ++i) {
        if (groupIndegree[i] == 0) {
            groupQueue.push(i);
        }
    }
    while (!groupQueue.empty()) {
        int g = groupQueue.front();
        groupQueue.pop();
        groupOrder.push_back(g);
        for (int nextGroup : groupGraph[g]) {
            groupIndegree[nextGroup]--;
            if (groupIndegree[nextGroup] == 0) {
                groupQueue.push(nextGroup);
            }
        }
    }
    if (groupOrder.size() != m) {
        return {};
    }
    vector<int> result;
    for (int g : groupOrder) {
        queue<int> itemQueue;
        for (int i = 0; i < n; ++i) {
            if (group[i] == g && itemIndegree[i] == 0) {
                itemQueue.push(i);
            }
        }

        while (!itemQueue.empty()) {
            int item = itemQueue.front();
            itemQueue.pop();
            result.push_back(item);
            for (int nextItem : itemGraph[item]) {
                itemIndegree[nextItem]--;
                if (itemIndegree[nextItem] == 0) {
                    itemQueue.push(nextItem);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (itemIndegree[i] > 0) {
            return {};
        }
    }

    return result;
}

int main() {
    int n = 8, m = 2;
    vector<int> group = {-1, -1, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> beforeItems = {
        {}, {6}, {5}, {6}, {3, 6}, {}, {}, {}
    };
    vector<int> sortedItems = sortItems(n, m, group, beforeItems);
    if (sortedItems.empty()) {
        cout << "No solution" << endl;
    } else {
        cout << "Sorted Items: ";
        for (int item : sortedItems) {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}