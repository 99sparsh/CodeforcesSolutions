#include <bits/stdc++.h>
#define mod 1000000007
#define FOR(i, a, b) for (i = a; i < b; i++)
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
void printV(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}
int modexp(int A, int B, int C)
{
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;
    int y;
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

    return (int)((y + C) % C);
}
class cmp
{
public:
    bool operator()(const pii &a, const pii &b) const
    {
        int lena = a.second - a.first + 1;
        int lenb = b.second - b.first + 1;
        if (lena == lenb)
            return a.first > b.first;
        return lena < lenb;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1, 0);
        priority_queue<pii, vector<pii>, cmp> pq;
        pq.push({1, n});
        int l, r;

        for (int i = 1; i <= n; i++)
        {
            pii top = pq.top();
            pq.pop();
            l = top.first;
            r = top.second;
            int len = r - l + 1;
            if (l == r)
            {
                v[l] = i;
                continue;
            }
            else if (len % 2 == 0)
            {

                int temp = (l + r - 1) / 2;
                v[temp] = i;
                pq.push({l, temp - 1});
                pq.push({temp + 1, r});
            }
            else
            {
                int temp = (l + r) / 2;
                v[temp] = i;
                pq.push({l, temp - 1});
                pq.push({temp + 1, r});
            }
        }
        for (int k = 1; k < v.size(); k++)
            cout << v[k] << " ";
        cout << '\n';
    }
}