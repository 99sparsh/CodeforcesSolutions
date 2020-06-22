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
        string s[n];
        for (ll i = 0; i < n; i++)
            cin >> s[i];
        int flag = 1;
        for (ll i = 0; i < n - 1; i++)
        {
            for (ll j = 0; j < n - 1; j++)
            {
                if (s[i][j] == '1' && s[i + 1][j] == '0' && s[i][j + 1] == '0')
                    flag = 0;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}