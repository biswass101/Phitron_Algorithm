#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool subsetSum(int *arr, int n, int sum)
{
    if(n == 0)
    {
        return sum == 0;
    }
    if(dp[n][sum] != -1)  return dp[n][sum]; 
    if(arr[n - 1] <= sum)
    {                                
        bool op1 = subsetSum(arr, n - 1, sum - arr[n - 1]); 
        bool op2 = subsetSum(arr, n - 1, sum);              
        return dp[n][sum] = op1 or op2;
    }
    else
    {
        bool op2 = subsetSum(arr, n - 1, sum);
        return dp[n][sum] = op2;
    }
}
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, marks;
        cin >> n >> marks;

        int a[n];
        for(int i = 0; i < n; i++)  cin >> a[i];
        int s = 1000 - marks;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }
        subsetSum(a, n, s) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}