#include<bits/stdc++.h>
using namespace std;

#define llint long long int

// O(1.618...^n) time complexity code
llint fib(int n) {
    // Base Case
    if (n == 0 || n == 1)
        return 1;
    
    // Decomposition Step
    llint a = fib(n-1);
    llint b = fib(n-2);

    // Recomposition Step
    return a + b;
}

// Driver Code
int main() {
    int n; 
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}

/*

Try to put n = 45 as input and you will see a considerable time delay the code takes to compute the answer! 

Lets improve that time in fib_memo.cpp. 

*/