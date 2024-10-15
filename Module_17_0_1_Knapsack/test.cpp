#include<bits/stdc++.h>
using namespace std;
const int N = 3;
void printMat(int n, int m, int dp[][N])
{
    for(int i = 0; i < n; i++)
    {
        for(int  j = 0; j < m; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    int dp[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printMat(3, 3, dp);
    return 0;
}