#include <bits/stdc++.h>
using namespace std;

int main() {

    set<char> s;  // Also sorts your unique values: unordered_set is also available.

    string temp; cin >> temp;

    for (auto c: temp) 
        s.insert(c);

    for (auto x: s)
        cout << x << " ";
    cout << endl;

    cout << s.size() << endl;

    char c1 = 'z'; 

    if (s.find(c1) == s.end()) {
        cout << c1 << " is not present.\n";
    } else 
        cout << "Present.\n";

    return 0;
}