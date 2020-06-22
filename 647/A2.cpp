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
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << "0\n";
            continue;
        }
        if ((a < b && b % a != 0) || (b < a && a % b != 0) || (a % 2 == 1 && b == 1 && a > b) || (b % 2 == 1 && a == 1 && b > a))
        {
            cout << "-1\n";
            continue;
        }
        if (a > b)
        {
            ll temp = b;
            b = a;
            a = temp;
        }
        if (a < b)
        {
            // ll q = log2(b / a);
            ll q = b / a;
            ll temp = q, count = 0;
            while (temp > 0 && temp % 2 == 0)
            {
                count++;
                temp >>= 1;
            }
            if (temp != 1)
            {
                cout << "-1\n";
                continue;
            }
            q = count;
            ll ans = 0;
            ans += q / 3;
            q = q % 3;
            ans += q / 2;
            q = q % 2;
            if (q == 1)
                ans++;
            cout << ans << '\n';
        }
    }
}