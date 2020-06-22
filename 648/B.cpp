#include <bits/stdc++.h>
#define mod 1000000007
#define FOR(i, a, b) for (i = a; i < b; i++)
using namespace std;
typedef long long ll;
void printV(vector<ll> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}
int modexp(ll A, ll B, ll C)
{
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;
    ll y;
    if (B % 2 == 0)
    {
        y = modexp(A, B / 2, C);
        y = (y * y) % C;
    }
    else
    {
        y = A % C;
        y = (y * modexp(A, B - 1, C) % C) % C;
    }

    return (ll)((y + C) % C);
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        ll o = 0, z = 0, x;
        for (ll i = 0; i < n; i++)
        {
            cin >> x;
            if (x == 1)
                o++;
            else
                z++;
        }
        int flag = 1;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "Yes\n";
            continue;
        }
        if (o == z)
        {
            cout << "Yes\n";
            continue;
        }
        if (o > z)
        {
            if (z > 0)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }
        if (z > 0)
        {

            if (0 > 0)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }
    }
}