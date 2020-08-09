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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        ll maxx = -1;
        int count = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            maxx = max(maxx, a[i]);
            if (a[i] == 0)
                count++;
        }
        if (count == n)
        {
            string words[] = {"fuck", "you"};
            for (ll i = 0; i <= n; i++)
                cout << words[i % 2] << '\n';
            continue;
        }
        string base = "";
        for (ll i = 0; i < maxx; i++)
            base += "a";
        cout << base << '\n';
        for (ll i = 0; i < n; i++)
        {

            string temp = "";
            temp = base;
            for (ll j = a[i]; j < maxx; j++)
            {
                if (base[j] == 'a')
                    temp[j] = 'b';
                else
                    temp[j] = 'a';
            }
            base = temp;
            cout << base << '\n';
        }
    }
}