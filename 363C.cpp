//Fixing typos
#include <bits/stdc++.h>
using namespace std;
main()
{
    string a, b = "";
    cin >> a;
    int l = a.size(), k;
    for (int i = 0; i < l; i++)
    {
        k = b.size();
        if (a[i] == a[i - 1] && a[i] == a[i - 2])
            continue;
        else if (k > 2 && a[i] == b[k - 1] && b[k - 2] == b[k - 3])
            continue;
        b += a[i];
    }
    cout << b << endl;
    return 0;
}