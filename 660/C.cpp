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
void dfs(vector<vector<ll>> &adj, ll n, ll src, bool vis[], ll pep[], ll p[])
{
    vis[src] = true;
    for (ll x : adj[src])
    {
        if (!vis[x])
        {
            dfs(adj, n, x, vis, pep, p);
            pep[src] += pep[x];
        }
    }
    pep[src] += p[src];
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, u, v;
        cin >> n >> m;
        ll p[n + 1], h[n + 1];
        for (ll i = 1; i <= n; i++)
            cin >> p[i];
        for (ll i = 1; i <= n; i++)
            cin >> h[i];
        vector<vector<ll>> graph(n + 1);
        for (ll i = 1; i <= n - 1; i++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //for (ll i = 1; i <= n; i++)
        //  sort(graph[i].begin(), graph[i].end());
        bool vis[n + 1];
        ll pep[n + 1];
        memset(pep, 0, sizeof(pep));
        dfs(graph, n, 1, vis, pep, p);
        bool flag = true;
        ll val;
        for (ll i = 1; i <= n; i++)
        {
            if (pep[i] == 0 && h[i] != 0)
            {
                flag = false;
                break;
            }
            val = h[i] + pep[i];
            if (val % 2 != 0)
            {
                flag = false;
                break;
            }
            else
            {
                ll good = val / 2;
                ll bad = good - h[i];
                if (!(good >= 0 && bad >= 0 && good - bad == h[i]))
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}