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
        ll n, k;
        cin >> n >> k;

        ll a[n], b[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        ll i = 0;
        while (k && i < n)
        {
            if (b[i] > a[i])
            {
                a[i] = b[i];
                k--;
            }
            i++;
        }
        ll ans = accumulate(a, a + n, 0);
        cout << ans << '\n';
    }
}