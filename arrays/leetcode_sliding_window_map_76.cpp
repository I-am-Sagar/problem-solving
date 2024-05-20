class Solution {
public:
    string minWindow(string s, string t) {
        // Lets create the first map for t
        map<char, int> t_freq;
        for (char c: t)
            t_freq[c]++;

        // How many unique chars are there in t
        int required_unique = t_freq.size();

        // Window, i to j in s, I need to make a map for that well
        map<char, int> window_freq;

        // Couple of variables
        int min_len = 10e6, min_window_left = 0, window_size = 0;
        int i = 0, j = 0;

        // Sliding window
        while (j < s.length()) {

            char c = s[j];
            window_freq[c]++;

            // Checking if the solution is kinda reached

            // find() == end() : element is not present
            if (t_freq.find(c) != t_freq.end() && window_freq[c] == t_freq[c])
                window_size++;

            // Can I shed elements from i'th side
            while (i <= j && window_size == required_unique) {
                // Update the minimum value of the length
                if (min_len > j - i + 1) {
                    min_len = j - i + 1;
                    min_window_left = i;
                }

                // Left char is 
                char left_char = s[i];

                // Can I remove this from window_freq
                window_freq[left_char]--;

                if (t_freq.find(left_char) != t_freq.end() && window_freq[left_char] < t_freq[left_char]) {
                    window_size--;
                }

                i++;
            }
            j++; 

            cout << i  << " " << j << endl;
        }

        return min_len == 10e6 ? "" : s.substr(min_window_left, min_len);
    }
};