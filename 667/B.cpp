#include <bits/stdc++.h>
#define mod 1000000007
#define FOR(i, a, b) for (i = a; i < b; i++)
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
int dxrow[] = {-1, 0, 0, 1, 1, 1, -1, -1}; //first 4 straight last 4 diagonals
int dycol[] = {0, -1, 1, 0, 1, -1, -1, 1};
void printV(vector<ll> v)
{
    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
}
ll power(ll a, ll b)
{
    return (ll)(pow(a, b) + 0.5);
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
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll ta = a, tb = b, tn = n;
        ta = ta - min((a - x), n);
        n = n - min((a - x), n);
        tb = tb - min(b - y, n);
        ll c1 = ta * tb;
        ta = a;
        tb = b;
        n = tn;
        tb = tb - min(b - y, n);
        n = n - min((b - y), n);
        ta = ta - min((a - x), n);
        ll c2 = ta * tb;
        ta = a;
        tb = b;
        n = tn;
        ll ad = a - x, bd = b - y;
        ta = ta - min(ad / 2, n);
        n = max(n - (ad / 2), 0ll);
        tb = tb - min(bd / 2, n);
        ll c3 = ta * tb;
        ta = a;
        tb = b;
        n = tn;
        tb = tb - min(bd / 2, n);
        n = max(n - (bd / 2), 0ll);
        ta = ta - min(ad / 2, n);
        ll c4 = ta * tb;
        ll ans = min({c1, c2, c3, c4});
        cout << ans << '\n';
    }
}