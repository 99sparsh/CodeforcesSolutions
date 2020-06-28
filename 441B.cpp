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
    int n, v, x, y, temp;
    cin >> n >> v;
    vector<int> v1(3002, 0);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v1[a] += b;
    }
    int carry = 0;
    int now = 0;
    int ans = 0;
    for (int i = 1; i <= 3001; i++)
    {
        now = v1[i];
        if (now + carry <= v)
        {
            ans += (now + carry);
            carry = 0;
        }
        else
        {
            ans += v;
            carry = now - max(v - carry, 0);
        }
    }
    cout << ans << endl;
}