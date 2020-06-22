#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll buckSize = n - 1;
        ll doneBucks = k / (n - 1);
        ll start = (doneBucks * n) + 1;
        ll considered = doneBucks * (n - 1);
        ll need = (k - considered - 1);
        ll ans = (start + need);
        if (k % (n - 1) == 0)
            ans--;
        cout << ans << '\n';
    }
}