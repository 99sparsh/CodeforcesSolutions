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
ll getMin(ll a)
{
    ll mind = 10;
    while (a)
    {
        mind = min(mind, a % 10);
        a /= 10;
    }
    return mind;
}
ll getMax(ll a)
{
    ll maxd = -1;
    while (a)
    {
        maxd = max(maxd, a % 10);
        a /= 10;
    }
    return maxd;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, k, ans;
        cin >> a >> k;
        if (k == 1)
        {
            cout << a << '\n';
            continue;
        }
        while (k--)
        {

            ll mind = getMin(a);
            ll maxd = getMax(a);
            if (mind == 0)
            {
                ans = a;
                break;
            }
            a += (mind * maxd);
            if (k == 1)
                break;
        }
        cout << a << '\n';
    }
}