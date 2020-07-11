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

//Omkar and Class of Math

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << (n / 2) << " " << (n / 2) << '\n';
        }
        else
        {
            ll lcm = LLONG_MAX, a = 1, b = n - 1;
            for (ll i = 3; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    ll f1 = i, f2 = n / i;
                    ll tempa1 = f1, tempb1 = (n - f1);
                    ll tempa2 = f2, tempb2 = (n - f2);
                    ll lcm1 = (tempa1 * tempb1) / __gcd(tempa1, tempb1);
                    ll lcm2 = (tempa2 * tempb2) / __gcd(tempa2, tempb2);
                    if (lcm1 < lcm)
                    {
                        a = tempa1;
                        b = tempb1;
                        lcm = lcm1;
                    }
                    if (lcm2 < lcm)
                    {
                        a = tempa2;
                        b = tempb2;
                        lcm = lcm2;
                    }
                }
            }
            cout << a << " " << b << '\n';
        }
    }
}