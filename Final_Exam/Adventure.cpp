#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 7;
const int maxW = 1e3 + 7;
int dp[maxN][maxW];
int knapsack(int n, int *weight, int *value, int w)
{
    if (n < 0 or w == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (weight[n] <= w)
    {
        int op1 = knapsack(n - 1, weight, value, w - weight[n]) + value[n];
        int op2 = knapsack(n - 1, weight, value, w);
        dp[n][w] = max(op1, op2);
        return dp[n][w];
    }
    else
    {
        int op2 = knapsack(n - 1, weight, value, w);
        dp[n][w] = op2;
        return dp[n][w];
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int w;
        cin >> w;
        int weight[n], value[n];
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                dp[i][j] = -1;
            }
        }
        int res = knapsack(n - 1, weight, value, w);
        cout << res << endl;
    }
    return 0;
}