#include <bits/stdc++.h>
using namespace std;
//Phoenix and Distribution
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] != s[k - 1])
    {
        cout << s[k - 1] << '\n';
        return;
    }
    cout << s[0];

    if (s[k] != s[n - 1])
    {
        for (int i = k; i < n; i++)
            cout << s[i];
    }
    else
    {

        for (int i = 0; i < (n - k + k - 1) / k; i++)
            cout << s[n - 1];
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}