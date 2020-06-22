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
        ll n, x, m;
        cin >> n >> x >> m;
        ll minn = x, maxx = x, l, r;
        for (ll i = 0; i < m; i++)
        {
            cin >> l >> r;
            if ((l >= minn && r <= maxx) || (l > maxx) || (r < minn))
                continue;
            minn = min(minn, l);
            maxx = max(maxx, r);
        }
        ans.push_back(maxx - minn + 1);
    }
    printV(ans);
}