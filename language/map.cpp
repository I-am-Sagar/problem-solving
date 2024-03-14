/* Question: Given the string, count each character in the string. 

    Solution: Whenever there is a need to count the number of occurences, 
    also known as frequency, you use maps. 

*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    // Step 1: Take input
    string str;
    cin >> str;

    map<char, int> m;
    for (auto c: str) {
        m[c]++;
    }

    // Print the map
    for (auto i: m) {
        cout << "(" << i.first << ", " << i.second << ") ";
    }
    cout << endl;

    return 0;
}