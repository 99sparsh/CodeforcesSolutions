#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<vector<int>> v[4];
vector<int> vv[100];
vector<int> team1;
int n, m;
bool vis[100];

void dfs(int u)
{
    team1.push_back(u);
    vis[u] = 1;

    for (auto x : vv[u])
        if (!vis[x])
            dfs(x);
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        vv[a].push_back(b);
        vv[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {

            team1.clear();
            dfs(i);
            if (team1.size() > 3)
            {
                cout << -1 << endl;
                return 0;
            }
            v[team1.size()].push_back(team1);
        }

    if (v[1].size() < v[2].size())
    {
        cout << -1 << endl;
        return 0;
    }

    for (auto team : v[3])
        cout << team[0] << " " << team[1] << " " << team[2] << endl;

    for (int i = 0; i < v[2].size(); i++)
        cout << v[2][i][0] << " " << v[2][i][1] << " " << v[1][i][0] << endl;

    for (int i = v[2].size(); i < v[1].size(); i += 3)
        cout << v[1][i][0] << " " << v[1][i + 1][0] << " " << v[1][i + 2][0] << endl;

    return 0;
}
