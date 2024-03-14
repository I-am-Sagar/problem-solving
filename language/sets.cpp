/* Question: You are given a string, for example "sagara", you have to return 
    the number of unique characters you see in the string. Here ans is 4, 
    because there are 4 unique characters: a g r s. 

    Solution: Whenever there is a mention of uniqueness or removal of duplicates,
    sets is used. I will put all characters inside the set and will return the 
    size of the set. 
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    // Step 1: Take the input
    string str;
    cin >> str;

    // Step 2: Put all the characters inside the set using for loop.
    set<char> s;
    for (auto c: str) {
        s.insert(c);
    }

    // Print the set, just to see the output
    // for (auto i: s) {
    //     cout << i << " ";
    // } 
    // cout << endl;

    cout << s.size() << endl;

    return 0;
}

/* Extra Points:

1. If you want to create a unique set of integers, use set<int> s. 

*/