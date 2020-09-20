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
        ll k;
        cin >> k;
        string n;
        cin >> n;
        ll ra = 0, br = 0;
        int marked[k];
        int ch = 1;
        memset(marked, 0, sizeof(marked));
        for (ll i = 0; i < k - 1; i++)
        {
            int f = 0;
            for (ll j = 0; j < k; j++)
            {
                if ((n[j] - '0') % 2 == 0 && (j + 1) % 2 == 1 && ch == 1 && marked[j] == 0)
                {

                    marked[j] = 1;
                    f = 1;
                    break;
                }
                else if ((n[j] - '0') % 2 == 1 && (j + 1) % 2 == 0 && ch == 2 && marked[j] == 0)
                {
                    marked[j] = 1;
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                for (ll j = 0; j < k; j++)
                {
                    if (ch == 1 && (j + 1) % 2 == 1 && marked[j] == 0)
                    {
                        marked[j] = 1;
                        break;
                    }
                    else if (ch == 2 && (j + 1) % 2 == 0 && marked[j] == 0)
                    {
                        marked[j] = 1;
                        break;
                    }
                }
            }
            ch = ch == 1 ? 2 : 1;
        }

        for (ll i = 0; i < k; i++)
        {
            if (marked[i] == 0)
            {
                if ((n[i] - '0') % 2 == 0)
                    cout << 2;
                else
                    cout << 1;
                cout << '\n';
                break;
            }
        }
    }
}