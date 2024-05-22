#include<bits/stdc++.h>
using namespace std;

vector<int> nsr(vector<int> arr) {
    int n = arr.size();
    stack<int> s;

    vector<int> result;

    for (int i = n-1; i >= 0; i--) {

        while (!s.empty() && s.top() >= arr[i])
            s.pop();

        if (s.empty())
            result.push_back(-1);
        else 
            result.push_back(s.top());

        s.push(arr[i]);
    }

    reverse(result.begin(), result.end());

    return result;
}

vector<int> nsl(vector<int> arr) {
    int n = arr.size();
    stack<int> s;

    vector<int> result;

    for (int i = 0; i < n; i++) {

        while (!s.empty() && s.top() >= arr[i])
            s.pop();

        if (s.empty())
            result.push_back(-1);
        else 
            result.push_back(s.top());

        s.push(arr[i]);
    }

    // reverse(result.begin(), result.end());

    return result;
}


int main() {

    vector<int> arr = {1, 3, 2, 2, 4, 1, 2, 1, 6};

    vector<int> ans = nsl(arr);

    for (auto x: ans) 
        cout << x  << " ";
    cout << endl;

    return 0;
} 