#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int k, m, n;
int a[55][55]; // 坐标 血量
char b[55][55];
int vis[55][55];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y)
{

    for (int i = 0; i < 4; ++i)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx <= 0 || xx > m || yy <= 0 || yy > n || b[xx][yy] == 'W' || vis[xx][yy])
            continue;

        vis[xx][yy] = 1;
        if (b[xx][yy] == 'X')
            a[xx][yy] = max(a[xx][yy], a[x][y] - 1);

        else
            a[xx][yy] = max(a[xx][yy], a[x][y]);

        dfs(xx, yy);
        vis[xx][yy] = 0;
    }
    return;
}
void solve()
{
    cin >> k >> m >> n;
    // m hang

    while (k--)
    {
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> b[i][j];
                a[i][j] = -2; // 未访问
            }
        }
        a[1][1] = 3;
        dfs(1, 1);

        if (a[m][n] >= 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}