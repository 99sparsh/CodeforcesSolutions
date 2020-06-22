#include <bits/stdc++.h>
#define mod 1000000007
#define FOR(i, a, b) for (i = a; i < b; i++)
using namespace std;
typedef long long ll;
void printV(vector<ll> v)
{
    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
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
    vector<ll> ans;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, ans = 0;
        cin >> n >> m;
        ll a[n][m];
        vector<pair<ll, ll>> d(n + m - 1);
        for (ll i = 0; i < n + m - 1; i++)
        {
            d[i].first = d[i].second = 0;
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 0)
                    d[i + j].first++;
                else
                    d[i + j].second++;
            }
        }
        for (ll start = 0; start < n + m - 1; start++)
        {
            ll end = n + m - 2 - start;
            if (end > start)
            {
                ll zeros = d[start].first + d[end].first;
                ll ones = d[start].second + d[end].second;
                ans += min(ones, zeros);
            }
        }
        cout << ans << '\n';
    }
}