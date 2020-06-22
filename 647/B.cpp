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
        ll n;
        cin >> n;
        ll a[n];
        unordered_set<ll> s;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        if (n == 1)
        {
            cout << "-1\n";
            continue;
        }
        ll k[n - 1];
        for (ll i = 1; i < n; i++)
        {
            k[i - 1] = a[0] ^ a[i];
        }
        ll min = LLONG_MAX;
        unordered_set<ll> check;
        int flag = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            check.clear();
            ll j = 0;
            for (j = 0; j < n; j++)
            {
                ll temp = k[i] ^ a[j];
                if (s.find(temp) != s.end())
                {
                    check.insert(temp);
                    continue;
                }
                else
                    break;
            }
            if (j == n)
            {
                if (s == check && k[i] < min)
                {
                    min = k[i];
                    flag = 1;
                }
            }
        }
        if (flag == 1)
            cout << min << '\n';
        else
            cout << "-1\n";
    }
}