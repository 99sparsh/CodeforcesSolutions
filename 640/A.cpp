#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> ans;
        ll x = 0;
        while (n)
        {
            ll temp = n % 10;
            ll temp2 = temp * pow(10, x++);
            if (temp2)
                ans.push_back(temp2);
            n /= 10;
        }
        cout << ans.size() << "\n";
        for (ll i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    }
}