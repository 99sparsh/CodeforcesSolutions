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
ll Log2n(ll n)
{
    return (n > 1) ? 1 + Log2n(n / 2) : 0;
}
int main()
{
    ll t;
    cin >> t;
    vector<ll> ans;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a == b)
        {
            ans.push_back(0);
            continue;
        }
        if (a > b)
        {
            ll temp = b;
            b = a;
            a = temp;
        }
        if (b % a != 0)
        {
            ans.push_back(-1);
            continue;
        }
        ll no = b / a;
        ll count = 0, temp = no;
        while (temp > 0 && temp % 2 == 0)
        {
            count++;
            temp >>= 1;
        }
        if (temp != 1)
        {
            ans.push_back(-1);
            continue;
        }
        ll dp[count + 1];
        for (ll i = 0; i <= count; i++)
            dp[i] = LLONG_MAX / 2;
        dp[0] = 0;
        for (ll i = 1; i <= count; i++)
        {
            for (ll j = 1; j <= 3; j++)
            {
                if (j <= i)
                {
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        }
        if (dp[count] == LLONG_MAX / 2)
            ans.push_back(-1);
        else
            ans.push_back(dp[count]);
    }
    for (ll i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
}