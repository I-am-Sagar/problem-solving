/*   PROBLEM STATEMENT: Minimum Steps to One

You are given a number 'n'. On this n, you can perform 3 operations.

a) If n is divisble by 3, you can divide it by 3.
b) If n is divisible by 2, you can divide it by 2. 
c) Otherwise, you can reduce the number by 1. 

What are the minimum number of operations required for n, so that it gets reduced to 1?

Example: I have number 5. It can be reduced to 1 in 3 steps. 
5 -> (reduce by 1) 4 -> (divide by 2) 2 -> (divide by 2) 1! OR
5 -> (reduce by 1) 4 -> (reduce by 1) 3 -> (divide by 3) 1!

How to solve it?

SOLUTION: 

It may look like it's a greedy question, but it is not. Consider this case when n = 10. 

You cannot divide this by 1. So greedily it is better to divide it by 2 and make it 5, than reduce it by 1 and make it 9. But,

10 -> 5 -> 4 -> 2 -> 1 (4 steps). 
10 -> 9 -> 3 -> 1 (3 steps).

min_steps_to_one(n) = 1 + min(a, b, c) 

where a = min_steps_to_one(n/3) if n is divisible by 3
      b = min_steps_to_one(n/2) if n is divisible by 2
      c = min_steps_to_one(n-1) 

*/

#include <bits/stdc++.h>
using namespace std;

int memo[100001];

int min_steps_to_one(int n) {
    if (n == 1)
        return 0;

    if (memo[n] != -1)
        return memo[n];

    int a = INT_MAX, b = INT_MAX, c = INT_MAX;

    if (n%3 == 0)
        a = min_steps_to_one(n/3) + 1;
    
    if (n%2 == 0)
        b = min_steps_to_one(n/2) + 1;
    
    c = min_steps_to_one(n-1) + 1;

    memo[n] = min(a, min(b, c));
    return memo[n];
}

int main() {
    int n; 
    cin >> n;

    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    cout << min_steps_to_one(n) << endl;
    return 0;
}

