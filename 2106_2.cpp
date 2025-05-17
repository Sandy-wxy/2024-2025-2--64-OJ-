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
int e[1003][1003], vis[1003][1003];
struct node
{
    int x, y;
    int h; //
};
void solve()
{
    int n, k, x, y, h;
    cin >> n >> k >> x >> y >> h;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            e[i][j] = 1;
            vis[i][j] = 0;
        }
    }
    for (int i = 1, a, b; i <= k; ++i)
    {
        cin >> a >> b;
        e[a][b] = 2;
        for (int j = 1; j <= 4; ++j)
        {
            int xx = a + dx[j];
            int yy = b + dy[j];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && e[xx][yy] == 1)
                e[xx][yy] = 0;
        }
    }

    // 并查集  siz  暴力找距离 贪心找距离

    deque<node> q;
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
    vis[x][y] = 1;
    i64 result = 0;
    result++;
    q.push_front(op);

    while (!q.empty())
    {
        op = q.front();
        q.pop_front();
        int x1, y1;
        int xx = op.x, yy = op.y;
        node oo;
        for (int i = 1; i <= 4; ++i)
        {
            x1 = xx + dx[i];
            y1 = yy + dy[i];
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && !vis[x1][y1])
            {

                if (e[x1][y1] == 1)
                {
                    vis[x1][y1] = 1;
                    result++;
                    oo.x = x1, oo.y = y1;
                    oo.h = op.h;

                    q.push_front(oo);
                }
                else if (e[x1][y1] == 2)
                {
                    continue;
                }
                else
                {
                    oo.x = x1, oo.y = y1;
                    oo.h = op.h - 1;

                    if (oo.h == 0)
                    {
                        continue;
                    }

                    vis[x1][y1] = 1;
                    result++;

                    q.push_back(oo);
                }
            }
        }
    }

    cout << result;
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