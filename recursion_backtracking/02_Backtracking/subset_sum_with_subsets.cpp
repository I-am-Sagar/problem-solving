#include<bits/stdc++.h>
using namespace std;


void subset_sum_with_subsets(int n, int sum, vector<int> &arr, vector<vector<int>> &result, vector<int> &path) {
    if (sum == 0) {
        result.push_back(path);
        return;
    }

    if (n < 0 || sum < 0)
        return;

    // Exclude/Skip the current element
    subset_sum_with_subsets(n-1, sum, arr, result, path);

    // Include/Pick the current element
    if (sum >= arr[n]) {
        path.push_back(arr[n]);
        subset_sum_with_subsets(n-1, sum-arr[n], arr, result, path);
        path.pop_back();
    }
}


int main() {
    int n, sum; cin >> n >> sum;
    vector<int> arr; 

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    } 

    vector<vector<int>> result;
    vector<int> path;

    subset_sum_with_subsets(n-1, sum, arr, result, path);

    for (auto subset: result) {
        for (int x: subset) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}