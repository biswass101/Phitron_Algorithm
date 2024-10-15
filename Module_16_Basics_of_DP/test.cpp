#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int dp[N];
int fibo(int n)
{
    if(n == 0 or n == 1) return n;
    //before call--->
    if(dp[n] != -1)
    {
        return dp[n];
    }
    int ans = fibo(n - 1)  + fibo(n - 2);
    dp[n] = ans;
    return ans;
}
int main()
{
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fibo(n) << endl;
    return 0;
}