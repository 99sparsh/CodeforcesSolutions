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
struct Cust
{
    bool operator()(pll &p1, pll &p2)
    {
        if (p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first > p2.first;
    }
};
int main()
{

    ll n, i;
    cin >> n;
    ll a[n], ex[n + 1], done[n + 1];
    for (i = 0; i <= n; i++)
        ex[i] = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        ex[a[i]]++;
    }
    if (a[0] >= 2)
    {
        cout << "-1\n";
        exit(0);
    }

    ll mex[n];
    mex[0] = a[0] == 0 ? 1 : 0;
    if (n == 1)
    {
        cout << mex[0] << '\n';
        exit(0);
    }
    priority_queue<pll, vector<pll>, Cust> pq;
    for (i = 0; i <= n; i++)
        pq.push({ex[i], i});
    int flag = 1;
    for (i = 0; i < n; i++)
    {
        pll v = pq.top();
        pq.pop();
        if (v.first > 0)
        {
            flag = 0;
            break;
        }
        if (done[v.second] != -1)
        {
            mex[i] = v.second;
            done[v.second] = 1;
        }
        ex[a[i]]--;
        pq.push({ex[a[i]], a[i]});
    }
    for (i = 0; i < n; i++)
        cout << mex[i] << " ";
}