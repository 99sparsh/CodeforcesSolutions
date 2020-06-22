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
    ll n, t1 = 0, t2 = 0;
    cin >> n;
    t1 = 24 * (ll)(pow(4, n - 3) + 0.5);
    if (n - 3 > 0)
        t2 = (n - 3) * 36 * (ll)(pow(4, n - 4) + 0.5);
    cout << (t1 + t2) << '\n';
}