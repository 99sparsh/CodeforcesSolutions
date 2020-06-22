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
long double avg(ll k, ll h, ll c)
{
    long double temp = (h * k + h + k * c) / double(2 * k + 1);
    return temp;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll h, c, temp;
        cin >> h >> c >> temp;
        if (temp == h)
        {
            cout << "1\n";
            continue;
        }
        if (temp == c)
        {
            cout << "2\n";
            continue;
        }
        if (temp <= (h + c) / 2)
        {
            cout << "2\n";
            continue;
        }

        ll low = 1, high = 1000000;
        long double diff = LDBL_MAX;
        ll ans;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            long double curr = avg(mid, h, c);
            // cout << "AVG: " << curr << '\n';
            if (abs(temp - curr) < diff)
            {
                diff = abs(temp - curr);
                ans = mid;
            }
            if (curr > temp)
                low = mid + 1;
            else if (curr < temp)
                high = mid - 1;
            else
                break;
        }
        // cout << diff << '\n';
        if (diff >= abs(h - temp))
            ans = 0;
        cout << (2 * ans) + 1 << '\n';
    }
}