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
        ll n, ans = 0, rem = 0;
        cin >> n;
        ll a[n];
        map<ll, ll> count;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            count[a[i]]++;
        }
        for (auto k : count)
        {
            ll a = k.first, b = k.second;
            b += rem;
            ans += (b / a);
            rem = b % a;
        }
        cout << ans << '\n';
    }
}