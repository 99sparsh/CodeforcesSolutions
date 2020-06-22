#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        unordered_set<pair<ll, ll>, hash_pair> k;
        ll x = 0, y = 0, ans = 0, dx = 0, dy = 0;
        k.insert({x, y});
        for (ll i = 0; i < s.length(); i++)
        {
            dx = x;
            dy = y;
            if (s[i] == 'N')
                y++;
            else if (s[i] == 'S')
                y--;
            else if (s[i] == 'E')
                x++;
            else
                x--;
            cout << "checking " << (dx + x) << " " << (dy + y) << '\n';
            if (k.find({dx + x, dy + y}) == k.end())
            {
                ans += 5;
                k.insert({dx + x, dy + y});
            }
            else
                ans += 1;
        }
        cout << ans << '\n';
    }
}