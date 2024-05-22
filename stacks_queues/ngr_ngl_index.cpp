#include<bits/stdc++.h>
using namespace std;

vector<int> ngr_i(vector<int> arr) {
    int n = arr.size();
    stack<int> s; // put the index in the stack

    vector<int> result; // put the index in the stack

    for (int i = n-1; i >= 0; i--) {

        while (!s.empty() && arr[s.top()] <= arr[i])
            s.pop();

        if (s.empty())
            result.push_back(-1);
        else 
            result.push_back(s.top());

        s.push(i);
    }

    reverse(result.begin(), result.end());

    return result;
}

vector<int> ngl_i(vector<int> arr) {
    int n = arr.size();
    stack<int> s;

    vector<int> result;

    for (int i = 0; i < n; i++) {

        while (!s.empty() && arr[s.top()] <= arr[i])
            s.pop();

        if (s.empty())
            result.push_back(-1);
        else 
            result.push_back(s.top());

        s.push(i);
    }

    // reverse(result.begin(), result.end());

    return result;
}


int main() {

    vector<int> arr = {1, 3, 2, 2, 4, 1, 2, 1, 6};

    vector<int> ans = ngl_i(arr);

    for (auto x: ans) 
        cout << x  << " ";
    cout << endl;

    return 0;
} 