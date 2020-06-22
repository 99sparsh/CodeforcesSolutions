#include <bits/stdc++.h>
#define mod 1000000007
#define FOR(i, a, b) for (i = a; i < b; i++)
using namespace std;
typedef long long ll;
void printV(vector<ll> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
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
int a[51][51];
bool checker(int r, int c, int n, int m)
{
    for (int i = 1; i <= m; i++)
        if (a[r][i] == 1)
            return false;
    for (int i = 1; i <= n; i++)
        if (a[i][c] == 1)
            return false;
    return true;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        }
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 0 && checker(i, j, n, m))
                {
                    a[i][j] = 1;
                    flag = 1 - flag;
                }
            }
        }
        if (flag == 0)
            cout << "Ashish\n";
        else
            cout << "Vivek\n";
    }
}