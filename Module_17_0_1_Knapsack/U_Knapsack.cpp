//top down solution-->
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 7;
// int dp[N][N];
// int knapsack(int n, int *weight, int *value, int w)
// {
//     if(n < 0 or w == 0) return 0;
//     if(dp[n][w] != -1)
//     {
//         return dp[n][w];
//     }
//     if(weight[n] <= w)
//     {
//         int op1 = knapsack(n - 1, weight, value, w - weight[n]) + value[n];
//         int op2 = knapsack(n - 1, weight, value, w);
//         return dp[n][w] = max(op1, op2); //assign + return assigned value to dp
//     }
//     else
//     {
//         int op2 = knapsack(n - 1, weight, value, w);
//         return dp[n][w] = op2;
//     }
// }
// int main()
// {
//     int n, w; cin >> n >> w;
//     int weight[n], value[n];
//     for(int i = 0; i < n; i++)
//     {
//         cin >> weight[i];
//         cin >> value[i];
//     }
//     //dp table init-->
//     for(int i = 0; i <= n; i++)
//     {
//         for(int j = 0; j <= w; j++)
//         {
//             dp[i][j] = -1;
//         }
//     }
//     cout << knapsack(n - 1, weight, value, w) << endl;
//     return 0;
// }

//bottom up solution -->

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, w; cin >> n >> w;
    int weight[n], value[n];
    for(int i = 0; i < n;i++)
    {
        cin >> weight[i];
        cin >> value[i];
    }

    int dp[n + 1][w + 1];

    //base case value intit. to dp table -->
    for(int i = 0; i <= n; i ++)
    {
        for(int j = 0; j <= w; j++)
        {
            if(i == 0 or j == 0) dp[i][j] = 0;
        }
    }

    //dp state -->
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(weight[i - 1] <= j) {
                
                int op1 = dp[i - 1][j - weight[i - 1]] + value[i - 1];
                int op2 = dp[i - 1][j];

                dp[i][j] = max(op1, op2);
            }
            else
            {
                int op2 = dp[i - 1][j];
                dp[i][j] = op2;
            }
        }
    }

    cout << dp[n][w] << endl;
    return 0;
}