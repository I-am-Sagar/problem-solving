#include<bits/stdc++.h>
using namespace std;

bool compare(pair<char, int> a, pair<char, int> b) {
    if (a.second > b.second)
        return true;
    else if (a.first < b.first)
        return true;
    return false;
}

int main() {

    map<char, int> m;  // Usecase: name : frequency

    string temp; cin >> temp;
    for (auto character: temp) {
        m[character]++;
    }

    // Interesting problem: Sort on frequencies
    vector<pair<char, int>> char_frequency;

    for (auto x: m) {
        char_frequency.push_back({x.first, x.second});
    }

    sort(char_frequency.begin(), char_frequency.end(), compare);

    string ans = "";
    for (auto x: char_frequency) {
        // cout << x.first << " " << x.second << endl;
        while (x.second--) {
            ans += x.first;
        }
    }

    cout << ans << endl;

    return 0;
}