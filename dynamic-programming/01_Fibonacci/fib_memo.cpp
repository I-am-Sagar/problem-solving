#include<bits/stdc++.h>
using namespace std;

#define llint long long int

// Memo table
llint memo[101];

// O(n) time complexity code
llint fib(int n) {
    // Base Case
    if (n == 0 || n == 1)
        return 1;
    
    // STEP 2: Before recursion, check if you know the answer
    if (memo[n] != -1)
        return memo[n];

    // Decomposition Step
    llint a = fib(n-1);
    llint b = fib(n-2);

    // Recomposition Step
    // STEP 3: Before returning the answer, store it for future
    memo[n] = a + b;
    return memo[n];
}

// Driver Code
int main() {
    int n; 
    cin >> n;

    // STEP 1: Initialize the memo table with -1
    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    cout << fib(n) << endl;

    return 0;
}

/*

It is not a good practice to keep the memo table global. However, it is a decent appraoch for problem solving as you dont need to worry on passing it in your recursion and keeping its track. 

The size of the global memo table I pick it from the 'constraints' section of the problem. If 0 <= n <= 100, I create the memo table of 101 i.e. (max value of n) + 1.

Now try putting n = 45 again as input and see the time difference in which you see the answer!

*/