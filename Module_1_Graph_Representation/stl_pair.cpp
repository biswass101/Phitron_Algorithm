#include<bits/stdc++.h>
using namespace std;
class Pair
{
    public:
        int first, second;
        void make_pair(int a, int b)
        {
            first = a;
            second = b;
        }
};
int main()
{
    // Pair p;
    // p.make_pair(10, 200);
    // cout << p.first << " " << p.second << endl;

    pair<int, int> pr;
    pr = make_pair(20, 30);
    cout << pr.first << " " << pr.second << endl;
    return 0;
}