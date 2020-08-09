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
    FastIO;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s1, s2, ans = "";
        cin >> s1 >> s2;
        ll a[n], b[n];
        for (ll i = 0; i < n; i++)
        {
            a[i] = s1[i] - '0';
            b[i] = s2[i] - '0';
        }
        ll count = 0, x = n - 1, temp;
        for (x = n - 1; x >= 1; x--)
        {
            if (a[0] == b[x])
            {
                count++;
                ans += "1 ";
                a[0] = a[0] ^ 1;
                count++;
                ans += to_string(x + 1) + " ";
                ll lim = x / 2;
                if (x % 2 == 0)
                    lim = (x - 1) / 2;
                for (ll j = 0; j <= lim; j++)
                {
                    a[j] = a[j] ^ 1;
                    a[x - j] = a[x - j] ^ 1;
                    temp = a[j];
                    a[j] = a[x - j];
                    a[x - j] = temp;
                }
                if (x % 2 == 0)
                    a[x / 2] = a[x / 2] ^ 1;
            }
            else
            {
                count++;
                ans += to_string(x + 1) + " ";
                int lim = x / 2;
                if (x % 2 == 0)
                    lim = (x - 1) / 2;
                for (ll j = 0; j <= lim; j++)
                {
                    a[j] = a[j] ^ 1;
                    a[x - j] = a[x - j] ^ 1;
                    temp = a[j];
                    a[j] = a[x - j];
                    a[x - j] = temp;
                }
                if (x % 2 == 0)
                    a[x / 2] = a[x / 2] ^ 1;
            }
        }
        if (a[0] != b[0])
        {
            count++;
            a[0] = a[0] ^ 1;
            ans += "1 ";
        }
        cout << count << ' ' << ans << '\n';
    }
}