#include <iostream>
#include <vector>
using namespace std;
int truckTour(vector<pair<int, int>>& petrolPumps) {
    int totalPetrol = 0, totalDistance = 0;
    int start = 0;
    int currentPetrol = 0;

    for (int i = 0; i < petrolPumps.size(); ++i) {
        totalPetrol += petrolPumps[i].first;
        totalDistance += petrolPumps[i].second;
        currentPetrol += petrolPumps[i].first - petrolPumps[i].second;
        if (currentPetrol < 0) {
            
            start = i + 1;
            currentPetrol = 0;
        }
    }
    return (totalPetrol >= totalDistance) ? start : -1;
}
int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> petrolPumps(N);
    for (int i = 0; i < N; ++i) {
        cin >> petrolPumps[i].first >> petrolPumps[i].second;
    }
    cout << truckTour(petrolPumps) << endl;
    return 0;
}
