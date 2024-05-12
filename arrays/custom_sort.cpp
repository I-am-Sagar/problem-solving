#include<bits/stdc++.h>
using namespace std;

bool compare_1(int a, int b) {
    string str_a = to_string(a);  // "9"
    string str_b = to_string(b);  // "98"

    string ab = str_a + str_b;
    string ba = str_b + str_a;

    // "998" > "989"
    return ab > ba;
}

bool compare_2(string a, string b) {
   return a.length() < b.length();
}

int main() {
    vector<int> nums = {9, 41, 98, 1, 7, 24, 53, 82};

    // Arrange them to form the largest number
    sort(nums.begin(), nums.end(), compare_1);

    for (auto x: nums)
        cout << x;
    cout << endl;

    string s = "i am a data scientist and i teach at heycoach";

    vector<string> words;

    // Learn it later: Splitting the sentence into the array of words
    stringstream str(s);
    string word;
    while (str >> word) 
        words.push_back(word);

    sort(words.begin(), words.end(), compare_2);

    for (auto x: words)
        cout << x << " ";
    cout << endl;

    return 0;
}