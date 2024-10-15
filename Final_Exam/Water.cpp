#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++)  cin >> arr[i];

        int mx = INT_MIN;
        int secMx = INT_MIN;

        int x, y;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > mx)
            {
                mx = arr[i];
                x = i;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(arr[i] > secMx and arr[i] != mx)
            {
                secMx = arr[i];
                y = i;
            }
        }

        if(x > y) cout << y << " " << x << endl; 
        else cout << x << " " << y << endl;    
    }
    return 0;
}