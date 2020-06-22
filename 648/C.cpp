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
    ll n;
    cin >> n;
    ll a[n], b[n];
    unordered_map<ll, pair<ll, ll>> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]].first = i;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        m[b[i]].second = i;
    }
    vector<ll> ans;
    for (auto i : m)
    {
        ll diff = i.second.first - i.second.second;
        if (diff < 0)
            diff += n;
        ans.push_back(diff);
    }
    unordered_map<int, int> freq;

    for (ll i : ans)
        freq[i]++;
    int max_count = 0, res = -1;
    for (auto i : freq)
    {
        if (max_count < i.second)
        {
            res = i.first;
            max_count = i.second;
        }
    }
    cout << max_count << '\n';
}
