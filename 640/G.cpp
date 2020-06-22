#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n < 4)
        {
            cout << "-1\n";
            continue;
        }
        for (ll i = n; i >= 1; i--)
        {
            if (i & 1)
                cout << i << ' ';
        }
        cout << "4 2 ";
        for (ll i = 6; i <= n; i += 2)
            cout << i << " ";
        cout << endl;
    }
}