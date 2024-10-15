#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
bool dp[N][N];
bool subset_sum(int n, int arr[], int s)
{
    if(n == 0)
    {
        if(s == 0) return true;
        else return false;
    }
    if(dp[n - 1][s]) return true;
    if(arr[n - 1] <= s)
    {
        bool op1 = subset_sum(n - 1, arr, s - arr[n - 1]);
        bool op2 = subset_sum(n - 1, arr, s);
        dp[n-1][s] = op1 or op2;
        return dp[n-1][s];
    }
    else
    {
        bool op2 = subset_sum(n - 1, arr, s);
        dp[n - 1][s] = op2;
        return dp[n - 1][s];
    }

}
int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int s; cin >> s;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= s; j++)
        {
            dp[i][j] = false;
        }
    }
    if(subset_sum(n, arr, s)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}