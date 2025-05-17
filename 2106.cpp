#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
int e[1003][1003], vis[1003][1003][6];
struct node
{
    int x, y;
    int h; //
};
void solve()
{
    int result = 0;
    int n, k, x, y, h;
    cin >> n >> k >> x >> y >> h;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            e[i][j] = 1;
        }
    }
    for (int i = 1, a, b; i <= k; ++i)
    {
        cin >> a >> b;
        for (int j = 0; j <= 4; ++j)
        {
            int xx = a + dx[j];
            int yy = b + dy[j];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n)
                e[xx][yy] = 0;
        }
    }

    // 并查集  siz  暴力找距离 贪心找距离

    deque<node> q;

    set<pair<int, int>> bns;
    node op;
    op.x = x, op.y = y, op.h = h;
    if (e[x][y] == 0)
    {
        op.h--;
    }

    if (op.h == 0)
    {
        cout << "0";
        return;
    }
    q.push_front(op);
    vis[x][y][op.h] = 1;
    bns.insert({x, y});

    while (!q.empty())
    {
        node cur = q.front();
        q.pop_front();

        for (int d = 1; d <= 4; ++d)
        {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 1 || nx > n || ny < 1 || ny > n)
                continue;

            int nh = cur.h;
            if (e[nx][ny] == 0)
                nh--;

            if (nh <= 0)
                continue;

            if (vis[nx][ny][nh])
                continue;
            vis[nx][ny][nh] = 1;

            if (![nx][ny])
            {
                occupied[nx][ny] = true;
                ++result;
            }

            q.push_back({nx, ny, nh});
            bns.insert({nx, ny});
        }
    }

    cout << bns.size() << '\n';
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