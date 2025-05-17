#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int k, m, n;
char a[55][55];
int b[55][55];
int vis[55][55];
struct node
{
    int i, j;
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void bfs()
{
    deque<node> q;
    q.push_back({1, 1});
    vis[1][1] = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop_front();
        if (x == m && y == n)
            continue;
        for (int i = 0; i < 4; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx <= 0 || x > m || yy <= 0 || yy > n || a[xx][yy] == 'W')
                continue;
            if (a[xx][yy] == 'X')
            {
                // b[xx][yy] = max(b[xx][yy], b[x][y] - 1);
                // if (b[xx][yy] >= 1)
                //     q.push_back({xx, yy});

                if (!vis[xx][yy])
                {
                    b[xx][yy] = max(b[xx][yy], b[x][y] - 1);
                    if (b[xx][yy] >= 1)
                        q.push_back({xx, yy});
                }

                else
                {
                    if (b[x][y] - 1 > b[xx][yy])
                    {
                        b[xx][yy] = max(b[xx][yy], b[x][y] - 1);
                        if (b[xx][yy] >= 1)
                            q.push_back({xx, yy});
                    }
                }
            }
            else
            {
                // b[xx][yy] = max(b[xx][yy], b[x][y]);
                // q.push_front({xx, yy});

                if (!vis[xx][yy])
                {
                    b[xx][yy] = max(b[xx][yy], b[x][y]);
                    if (b[xx][yy] >= 1)
                        q.push_front({xx, yy});
                }

                else
                {
                    if (b[x][y] > b[xx][yy])
                    {
                        b[xx][yy] = max(b[xx][yy], b[x][y]);
                        if (b[xx][yy] >= 1)
                            q.push_front({xx, yy});
                    }
                }
            }

            vis[xx][yy] = 1;
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
                b[i][j] = -2;
                vis[i][j] = 0;
            }
        }
        b[1][1] = 3;
        bfs();
        if (b[m][n] >= 1)
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