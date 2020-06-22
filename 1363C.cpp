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
        ll n, x;
        cin >> n >> x;
        if (n == 1)
        {
            cout << "Ayush\n";
            continue;
        }
        ll deg[n + 1];
        memset(deg, 0, sizeof(deg));
        for (ll i = 1; i <= n - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
        }
        if (deg[x] == 1)
        {
            cout << "Ayush\n";
            continue;
        }
        if (n % 2)
            cout << "Ashish\n";
        else
            cout << "Ayush\n";
    }
}