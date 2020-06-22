#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int a, b, c, d;
    while (t--)
    {
        cin >> a >> b >> c >> d;
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        if (b == d && a + c == b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}