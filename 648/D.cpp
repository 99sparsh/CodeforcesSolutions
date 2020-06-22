#include <bits/stdc++.h>
#define mod 1000000007
#define FOR(i, a, b) for (i = a; i < b; i++)
using namespace std;
typedef long long ll;
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
bool isSafe(int i, int j, int n, int m)
{
    if (
        i >= 0 && i < n && j >= 0 && j < m)
        return true;
    return false;
}
bool isPath(string graph[], int r, int c, int n, int m)
{
    bool visited[n][m];
    memset(visited, false, sizeof visited);
    visited[r][c] = true;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();
        if (f.first == n - 1 && f.second == m - 1)
            return true;
        for (int i = 0; i < 4; i++)
        {
            int row = f.first + rowNum[i];
            int col = f.second + colNum[i];
            if (isSafe(row, col, n, m) && graph[row][col] != '#' && !visited[row][col])
            {
                visited[row][col] = true;
                q.push({row, col});
            }
        }
    }
    return false;
}
bool checker(string graph[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'G')
            {
                bool flag = isPath(graph, i, j, n, m);
                if (!flag)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        string graph[n];
        for (int i = 0; i < n; i++)
            cin >> graph[i];
        int G = 0, B = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (graph[i][j] == 'G')
                    G++;
                if (graph[i][j] == 'B')
                    B++;
            }
        }
        if (G == 0)
        {
            cout << "Yes\n";
            continue;
        }
        if (!checker(graph, n, m))
        {
            cout << "No\n";
            continue;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (graph[i][j] == '.')
                {
                    graph[i][j] = '#';
                    if (!checker(graph, n, m))
                        graph[i][j] = '.';
                }
            }
        }
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (graph[i][j] == 'B')
                {
                    if (isPath(graph, i, j, n, m))
                    {
                        ans = false;
                        break;
                    }
                }
                if (!ans)
                    break;
            }
        }
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}