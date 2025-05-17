#include <bits/stdc++.h>
using namespace std;
int k, m, n;
const int N = 55;
char a[N][N];
int vis[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dfs(int x, int y, int c)
{
    if (x == m && y == n && c >= 1)
    {
        return 1;
    }

    for (int i = 0; i < 4; ++i)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx <= 0 || xx > m || yy <= 0 || yy > n)
            continue;
        if (vis[xx][yy] || a[xx][yy] == 'W')
            continue;
        vis[xx][yy] = 1;
        int cc = c;
        if (a[xx][yy] == 'X')
            cc--;
        if (cc == 0)
            continue;
        if (dfs(xx, yy, cc))
            return 1;
        vis[xx][yy] = 0;
    }

    return 0;
}
int main()
{
    cin >> k >> m >> n;
    while (k--)
    {

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
                cin >> a[i][j];
        }
        vis[1][1] = 1;

        if (dfs(1, 1, 3))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
