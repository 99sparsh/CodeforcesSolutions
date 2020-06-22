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
        ll n, k;
        cin >> n >> k;
        ll b = ceil((double)k / (n - 1));
        ll start = n * (b - 1) + 1;
        ll end = (n - 1) * b - (n - 2);
        ll temp = k - end;
        // temp++;
        // for (ll i = start; i <= end; i++)
        // {
        //     if (temp == k)
        //     {
        //         cout << i << "\n";
        //         break;
        //     }
        //     temp++;
        // }
        cout << (start + temp) << '\n';
    }
}