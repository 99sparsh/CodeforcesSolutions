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
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        ll lastA = a[0], lastB = 0, A = 1, B = n - 1;
        ll ans1 = a[0], ans2 = 0, Acurr = 0, Bcurr = 0, moves = 1;
        int cur = 0;
        while (A <= B)
        {
            if (!cur)
            {
                while (Bcurr <= lastA && B >= A)
                {
                    Bcurr += a[B];
                    ans2 += a[B];
                    B--;
                }
                lastB = Bcurr;
                Bcurr = 0;
            }
            else
            {
                while (Acurr <= lastB && A <= B)
                {
                    Acurr += a[A];
                    ans1 += a[A];
                    A++;
                }
                lastA = Acurr;
                Acurr = 0;
            }
            cur = 1 - cur;
            moves++;
        }
        cout << moves << " " << ans1 << " " << ans2 << "\n";
    }
}