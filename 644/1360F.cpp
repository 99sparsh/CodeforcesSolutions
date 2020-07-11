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
        ll n, m;
        cin >> n >> m;
        string a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        string ans = a[0];
        bool flag = true;
        for (int i = 0; i < m; i++)
        {
            char temp = ans[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                flag = true;
                ans[i] = c;

                for (int j = 0; j < n; j++)
                {
                    int err = 0;
                    for (int k = 0; k < m; k++)
                    {
                        if (a[j][k] != ans[k])
                            err++;
                    }
                    if (err > 1)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    cout << ans << '\n';
                    break;
                }
            }
            if (flag)
                break;

            ans[i] = temp;
        }
        if (!flag)
            cout << "-1\n";
    }
}