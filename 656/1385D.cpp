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

ll recur(string s, ll l, ll r, char c, int sw)
{
    if (l == r)
    {
        if (s[l] != c)
            return 1;
        return 0;
    }
    if (sw == 0)
    {
        ll count = 0, mid = (r + l) / 2;
        for (ll i = l; i <= mid; i++)
        {
            if (s[i] != c)
                count++;
        }
        return count + min(recur(s, mid + 1, r, c + 1, 0), recur(s, mid + 1, r, c + 1, 1));
    }
    else
    {
        ll count = 0, mid = (r + l) / 2;
        for (ll i = mid + 1; i <= r; i++)
        {
            if (s[i] != c)
                count++;
        }
        return count + min(recur(s, l, mid, c + 1, 0), recur(s, l, mid, c + 1, 1));
    }
}
int main()
{
    FastIO;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = min(recur(s, 0, n - 1, 'a', 0), recur(s, 0, n - 1, 'a', 1));
        cout << ans << '\n';
    }
}