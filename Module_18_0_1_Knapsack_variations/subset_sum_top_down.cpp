#include<bits/stdc++.h>
using namespace std;
bool subset_sum(int n, int arr[], int s)
{
    if(n == 0)
    {
        if(s == 0) return true;
        else return false;
    }
    if(arr[n - 1] <= s)
    {
        bool op1 = subset_sum(n - 1, arr, s - arr[n - 1]);
        bool op2 = subset_sum(n - 1, arr, s);
        return op1 or op2;
    }
    else
    {
        bool op2 = subset_sum(n - 1, arr, s);
        return op2;
    }

}
int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int s; cin >> s;

    if(subset_sum(n, arr, s)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}