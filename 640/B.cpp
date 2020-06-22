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
        ll n, k;
        cin >> n >> k;
        if ((n % 2 == 1 && k % 2 == 0) || (k > n))
        {
            cout << "NO\n";
            continue;
        }
        if (n == k)
        {
            cout << "YES\n";
            for (ll i = 1; i <= n; i++)
                cout << "1 ";

            cout << '\n';
            continue;
        }
        if (n % 2 == 1)
        {
            cout << "YES\n";
            for (int i = 1; i <= k - 1; i++)
                cout << "1 ";
            cout << (n - (k - 1)) << "\n";
            continue;
        }
        if (n % 2 == 0 && k <= n / 2)
        {
            cout << "YES\n";
            for (int i = 1; i <= k - 1; i++)
                cout << "2 ";
            cout << (n - 2 * (k - 1)) << "\n";
            continue;
        }
        if (n % 2 == 0 && k <= n && k % 2 == 0)
        {
            cout << "YES\n";
            for (int i = 1; i <= k - 1; i++)
                cout << "1 ";
            cout << (n - (k - 1)) << "\n";
            continue;
        }
        if (n % 2 == 0 && k > n / 2 && k % 2 == 1)
        {
            cout << "NO\n";
            continue;
        }
    }
}