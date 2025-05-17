#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
#define int i64
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

const int N = 1e3 + 10;
int a[N][N], dp[N][N], vis[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            vis[i][j] = 0;
            dp[i][j] = 0;
        }
    }

    queue<pair<int, int>> q;
    q.push({n, m});
    dp[n][m] = a[n][m];
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();

        for (int i = 0; i <= 1; ++i)
        {
            int xx = t.first + dx[i];
            int yy = t.second + dy[i];
            if (xx >= 1 && yy >= 1 && vis[xx][yy] == 0)
            {

                vis[xx][yy] = 1;
                q.push({xx, yy});
            }
        }

        for (int i = 2; i <= 3; ++i)
        {
            int xx = t.first + dx[i];
            int yy = t.second + dy[i];
            if (xx <= n && yy <= m)
            {
                dp[t.first][t.second] = max(dp[t.first][t.second], a[t.first][t.second] + dp[xx][yy]);
            }
        }
    }

    cout << dp[1][1];
}

signed main()
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