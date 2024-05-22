#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s1;
    stack<string> s2;

    s1.push(1);
    s1.push(3);
    s1.push(7);

    for (int i = 4; i < 7; i++)
        s1.push(i);         // I am pushing 4, 5, 6

    // Total 6 elements in s1: Order of push: 1 3 7 4 5 6

    while (!s1.empty()) {
        int temp = s1.top();
        cout <<temp << " ";
        s1.pop();
    }
    cout << endl;

    s2.push("sagar");
    s2.push("vishnu");
    s2.push("shreya");

    while (!s2.empty()) {
        string temp = s2.top();
        cout << temp << " ";
        s2.pop();
    }
    cout << endl;

    return 0;
}