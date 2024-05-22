#include<bits/stdc++.h>
using namespace std;

vector<int> nsr_i(vector<int> arr) {
    int n = arr.size();
    // first element is the array value, second element is index
    stack<pair<int, int>> s;

    vector<int> result;

    for (int i = n-1; i >= 0; i--) {

        while (!s.empty() && s.top().first >= arr[i])
            s.pop();

        if (s.empty())
            result.push_back(n);
        else 
            result.push_back(s.top().second);

        s.push({arr[i], i});
    }

    reverse(result.begin(), result.end());

    return result;
}

vector<int> nsl_i(vector<int> arr) {
    int n = arr.size();
    stack<pair<int, int>> s;

    vector<int> result;

    for (int i = 0; i < n; i++) {

        while (!s.empty() && s.top().first >= arr[i])
            s.pop();

        if (s.empty())
            result.push_back(-1);
        else 
            result.push_back(s.top().second);

        s.push({arr[i], i});
    }

    // reverse(result.begin(), result.end());

    return result;
}


int main() {

    vector<int> hist = {6, 2, 5, 4, 5, 1, 6};

    vector<int> nsr_index = nsr_i(hist);
    vector<int> nsl_index = nsl_i(hist);

    // cout << "NSR_i: ";
    // for (auto x: ans) 
    //     cout << x  << " ";
    // cout << endl;

    // cout << "NSL_i: ";
    // for (auto x: ans2) 
    //     cout << x << " ";
    // cout << endl;

    vector<int> width;

    for (int i = 0; i < hist.size(); i++) {
        int w = nsr_index[i] - nsl_index[i] - 1;
        width.push_back(w);
    }

    // cout << "WIDTH: ";
    // for (auto x: width)
    //     cout << x << " ";
    // cout << endl;

    int max_area = 0;
    for (int i = 0; i < width.size(); i++) {
        int area = hist[i]*width[i];
        max_area = max(max_area, area);
    }

    cout << max_area << endl;

    return 0;
} 