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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 1)
        {
            cout << s << '\n';
            continue;
        }
        ll a[n];
        for (ll i = 0; i < n; i++)
            a[i] = s[i] - '0';
        ll b[n], count[n], x = 0, c;
        ll i = 0, j;
        while (i < n)
        {
            c = 0;
            for (j = i; j < n; j++)
            {
                if (a[i] == a[j])
                    c++;
                else
                    break;
            }
            b[x] = a[i];
            count[x] = c;
            x++;
            i = j;
        }
        int flag = -1;
        for (i = 0; i < x - 1; i++)
        {
            if (b[i] == 1 && b[i + 1] == 0 && flag == -1)
            {
                count[i] = 0;
                count[i + 1] = 1;
                flag = 1;
                i++;
            }
            else if (b[i] == 1 && b[i + 1] == 0 && flag == 1)
            {
                count[i] = 0;
                count[i + 1] = 0;
                i++;
            }
        }
        string ans = "";
        for (i = 0; i < x; i++)
        {
            for (j = 0; j < count[i]; j++)
                if (b[i] == 0)
                    ans += '0';
                else
                    ans += '1';
        }
        cout << ans << '\n';
    }
}