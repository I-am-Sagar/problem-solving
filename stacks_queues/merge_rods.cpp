#include<bits/stdc++.h>
using namespace std;

int min_cost_rods_merge(vector<int> arr) {
    int cost = 0;

    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (auto x: arr)
        min_heap.push(x);

    while (min_heap.size() > 1) {
        int rod1 = min_heap.top(); min_heap.pop();
        int rod2 = min_heap.top(); min_heap.pop();

        cost += rod1 + rod2;

        min_heap.push(rod1+rod2);
    }

    return cost;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 1, 4};

    cout << min_cost_rods_merge(arr) << endl;

    return 0;
}