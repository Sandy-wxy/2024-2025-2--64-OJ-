#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int k, m, n;
char a[55][55];
int b[55][55];
int vis[55][55];

struct node
{
    int i, j, cost;
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs()
{
    deque<node> q;
    q.push_back({1, 1, 0});
    vis[1][1] = 0;

    while (!q.empty())
    {
        auto [x, y, now_cost] = q.front();
        q.pop_back();
        if (vis[x][y] != now_cost)
            continue; // 如果 vis[x][y] == now_cost 的话，那么这个点一定是第一次进行访问

        for (int i = 0; i < 4; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx <= 0 || x > m || yy <= 0 || yy > n || a[xx][yy] == 'W')
                continue;

            if (vis[xx][yy] > now_cost + (a[xx][yy] == 'X'))
            {
                vis[xx][yy] = now_cost + (a[xx][yy] == 'X');
                if (a[xx][yy] == 'X')
                    q.push_back({xx, yy, vis[xx][yy]});
                else
                    q.push_front({xx, yy, vis[xx][yy]});
            }
        }
    }
}
void solve()
{
    cin >> k >> m >> n;
    while (k--)
    {
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> a[i][j];
                // 不需要 b 了，只需要 vis[i][j] 记录到 i j 的最小花费即可，所以都先定义为一个很大的值就行
                vis[i][j] = 100;
            }
        }

        bfs();

        if (vis[m][n] <= 3)
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