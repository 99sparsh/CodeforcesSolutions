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
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, ans = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        ll ones = count(s.begin(), s.end(), '1');
        if (ones == 0)
        {
            ans = ceil(double(n) / (k + 1));
            //ans = n / (k + 1);
            cout << ans << '\n';
            continue;
        }
        vector<ll> diff;
        ll c = 0;
        while (s[c] != '1')
            c++;
        // cout << "C: " << c << '\n';
        if (c > k)
            diff.push_back(c - k); //0 to 1st 1
        ll left = c;
        ans = 0;
        if (ones == 1)
        {
            // cout << "HERE";
            ans = 0;
            ans += c / (k + 1);
            //cout << "k:" << k;
            ans += (n - c - 1) / (k + 1);
            //cout << "final" << ans;
            cout << ans << '\n';
            continue;
        }

        for (ll i = left + 1; i < n; i++)
        {
            if (s[i] == '1')
            {
                if ((i - left - 1) > 2 * k)
                    diff.push_back(i - left - 1 - 2 * k);
                left = i;
            }
        }
        if (n - left - 1 > k)
            diff.push_back(n - left - 1 - k); //last 1 to end
                                              // printV(diff);
        for (ll e : diff)
        {

            ans += ceil(double(e) / (k + 1));
        }
        cout << ans << '\n';
    }
}