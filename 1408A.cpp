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
        cout << v[i] << " ";
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
        ll n;
        cin >> n;
        ll a[n], b[n], c[n], i;
        FOR(i, 0, n)
        {
            cin >> a[i];
        }
        FOR(i, 0, n)
        {
            cin >> b[i];
        }
        FOR(i, 0, n)
        {
            cin >> c[i];
        }
        vector<ll> ans = {a[0]};

        ll x = 1;
        while (x < n)
        {
            if (a[x] == ans[x - 1])
                ans.push_back(b[x]);
            else
                ans.push_back(a[x]);
            x++;
        }
        if (ans[0] == ans[n - 1])
        {
            if (a[n - 1] != ans[n - 2] && a[n - 1] != ans[0])
                ans[n - 1] = a[n - 1];
            else if (b[n - 1] != ans[n - 2] && b[n - 1] != ans[0])
                ans[n - 1] = b[n - 1];
            else
                ans[n - 1] = c[n - 1];
        }
        printV(ans);
        cout << '\n';
    }
}