#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 7;
ll dp[N];
bool make_it(ll src, ll target)
{
    if (src == target) return true;
    else if (src > target) return false;
    if (dp[src] != -1)  return dp[src];

    bool op1 = make_it(src + 3, target);
    bool op2 = make_it(src * 2, target);

    return dp[src] = op1 or op2;
}
void clear_and_settt(int n)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
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
        clear_and_settt(n);
        if (n == 1)
            cout << "YES" << endl;
        else
        {
            if (make_it(1, n))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}