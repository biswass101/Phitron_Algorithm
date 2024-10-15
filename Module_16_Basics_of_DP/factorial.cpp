#include<bits/stdc++.h>
using namespace std;
int getFact(int n)
{
    if(n == 0) return 1;
    int get_sub_fact = getFact(n - 1);
    return n * get_sub_fact;
}
int main()
{
    int n; cin >> n;
    cout << getFact(n) << endl;
    return 0;
}