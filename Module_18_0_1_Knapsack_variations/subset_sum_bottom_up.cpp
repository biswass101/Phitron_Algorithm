#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int s; cin >> s;

    bool dp[n+1][s+1];
    dp[0][0] = true;
    for(int i = 1; i <= s; i++)
    {
        dp[0][i] = false;
    }
    return 0;
}