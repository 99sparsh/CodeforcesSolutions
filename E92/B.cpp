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
        ll n, k, z;
        cin >> n >> k >> z;
        ll a[n], sum = 0, flag = 1;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        // if (z == 0)
        // {
        //     cout << sum << '\n';
        //     continue;
        // }
        if (k == 1)
        {
            cout << a[0] + a[1] << '\n';
            continue;
        }

        ll maxp = 0, maxi = -1;
        for (ll i = 0; i < k; i++)
        {
            if (maxp < a[i] + a[i + 1])
            {
                maxp = a[i] + a[i + 1];
                maxi = i + 1;
            }
        }
        // cout << "MAXI: " << maxi << '\n';
        ll ans = 0;
        for (ll i = 0; i <= maxi; i++)
        {
            ans += a[i];
            k--;
        }
        k++;
        //cout << "K " << k << '\n';
        if (k == 0)
        {
            cout << ans << '\n';
            continue;
        }
        ll x = 0;
        while (k > 0 && z > 0)
        {
            //cout << "K HERE: " << k << '\n';
            if (!x)
            {
                ans += a[maxi - 1];
                z--;
            }
            else
                ans += a[maxi];
            k--;
            x = 1 - x;
        }
        // cout << k << " " << z << " H" << '\n';
        if (z == 0 && x == 0)
            maxi++;
        while (k > 0)
        {
            if (maxi < n)
                ans += a[maxi++];
            k--;
        }
        cout << ans << '\n';
    }
}