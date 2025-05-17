#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 60;
int w[N][N];
bool vis[N][N];
int dis[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
struct node
{
    int i, j;
};
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> w[i][j];
            dis[i][j] = 1e9;
        }
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    dis[a][b] = 1;
    queue<node> q;
    q.push({a, b});
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx == c && yy == d)
            {
                dis[c][d] = min(dis[x][y] + 1, dis[c][d]);
            }
            else if (w[xx][yy])
            {
            }
        }
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