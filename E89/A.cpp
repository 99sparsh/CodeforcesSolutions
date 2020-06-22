#include <bits/stdc++.h>
#define mod 1000000007
#define FOR(i, a, b) for (i = a; i < b; i++)
using namespace std;
typedef long long ll;
void printV(vector<ll> v)
{
    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
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
    vector<ll> answer;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a == 0 || b == 0)
        {
            answer.push_back(0);
            continue;
        }
        ll maxx = max(a, b);
        ll minn = min(a, b);
        if (maxx >= 2 * minn)
        {
            answer.push_back(minn);
            continue;
        }

        answer.push_back((maxx + minn) / 3);
    }
    printV(answer);
}