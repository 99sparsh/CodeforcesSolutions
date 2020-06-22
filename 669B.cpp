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
    unordered_set<ll> s;
    string jumps;
    cin >> jumps;
    ll lens[n];
    for (ll &e : lens)
        cin >> e;
    ll curr = 0;
    s.insert(curr);
    int flag = 0;
    while (curr >= 0 && curr < n)
    {
        if (jumps[curr] == '>')
            curr += lens[curr];
        else
            curr -= lens[curr];
        if (s.find(curr) != s.end())
        {
            flag = 1;
            break;
        }
        s.insert(curr);
    }
    if (flag)
        cout << "INFINITE\n";
    else
        cout << "FINITE\n";
}