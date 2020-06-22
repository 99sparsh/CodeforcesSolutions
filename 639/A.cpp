#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    int n, m;
    while (t--)
    {
        cin >> n >> m;
        if (n == 1 || m == 1)
            cout << "YES\n";
        else if (n == 2 && m == 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}