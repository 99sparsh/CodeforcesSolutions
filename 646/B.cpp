#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int suf0 = 0, suf1 = 0;
        for (auto &it : s)
        {
            suf0 += (it == '0');
            suf1 += (it == '1');
        }
        int ans = min(suf0, suf1); //Make whole string 0/1
        int pref0 = 0, pref1 = 0;
        for (auto &it : s)
        {
            pref0 += (it == '0'), suf0 -= (it == '0');
            pref1 += (it == '1'), suf1 -= (it == '1');
            //Cost of making string 0*1*
            ans = min(ans, pref1 + suf0);
            //Cost of making string 1*0*
            ans = min(ans, pref0 + suf1);
        }
        cout << ans << endl;
    }
    return 0;
}