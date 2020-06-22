#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
ll findmid(ll s)
{
    ll l = 1, r = s;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll sum = mid * (3 * mid + 1) / 2;
        ll sum2 = (mid + 1) * (3 * mid + 4) / 2;
        if (sum == s)
            return mid;
        else if (sum > s)
            r = mid - 1;
        else
        {
            if (sum2 > s)
                return mid;
            l = mid + 1;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    int n, m;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        while (n > 1)
        {
            ll temp = findmid(n);
            //  cout << "TEMP: " << temp;
            ans++;
            n -= (temp * (3 * temp + 1) / 2);
        }
        cout << ans << '\n';
    }
}