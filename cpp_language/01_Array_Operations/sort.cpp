#include<bits/stdc++.h>
using namespace std;

int main() {

    // Normal integer array
    int arr[] = {3, 4, 7, 1, 2, 9, 0, 2, 6, 5};
    int n = sizeof(arr)/sizeof(arr[0]);  
    sort(arr, arr+n);

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;

    // Vector sort
    vector<int> arr2 = {3, 4, 7, 1, 2, 9, 0, 2, 6, 5};
    sort(arr2.begin(), arr2.end());

    for (auto x: arr2)
        cout << x << " ";
    cout << endl;

    // Normal string array
    string arr3[] = {"sagar", "hari", "vishnu", "ashutosh"};
    int n2 = sizeof(arr3)/sizeof(arr3[0]);
    sort(arr3, arr3+n2);

    for (int i = 0; i < n2; i++)
        cout << arr3[i] << " ";
    cout << endl;

    // Vector sort of strings
    vector<string> arr4 = {"sagar", "hari", "vishnu", "ashutosh"};
    sort(arr4.begin(), arr4.end());

    for (auto x: arr4)
        cout << x << " ";
    cout << endl;

    // Use greater<int>() to sort in descending order
    int arr5[] = {3, 4, 7, 1, 2, 9, 0, 2, 6, 5};
    int n3 = sizeof(arr)/sizeof(arr[0]);  
    sort(arr5, arr5+n, greater<int>());

    for (int i = 0; i < n; i++) 
        cout << arr5[i] << " ";
    cout << endl;

    // Use greater<string>() to sort strings in descending order
    vector<string> arr6 = {"sagar", "hari", "vishnu", "ashutosh"};
    sort(arr6.begin(), arr6.end(), greater<string>());

    for (auto x: arr6)
        cout << x << " ";
    cout << endl;


    return 0;
}