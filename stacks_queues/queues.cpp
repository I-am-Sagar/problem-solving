#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q1;
    queue<string> q2;

    q1.push(1);
    q1.push(3);
    q1.push(7);

    for (int i = 4; i < 7; i++)
        q1.push(i);         // I am pushing 4, 5, 6

    // Total 6 elements in q1: Order of push: 1 3 7 4 5 6

    while (!q1.empty()) {
        int temp = q1.front();
        cout <<temp << " ";
        q1.pop();
    }
    cout << endl;

    q2.push("sagar");
    q2.push("vishnu");
    q2.push("shreya");

    while (!q2.empty()) {
        string temp = q2.front();
        cout << temp << " ";
        q2.pop();
    }
    cout << endl;

    return 0;
}