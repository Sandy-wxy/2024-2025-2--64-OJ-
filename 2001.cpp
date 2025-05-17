// OJ:2001
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int m, n;
int ans = 0;
int h[10], l[10];
void dfs(int x, int y)
{
    if (x == n && y == n && h[n] <= m && l[n] == h[n])
    {
        ans++;
        return;
    }
    if (h[x] > m || l[y] > m || (x == n && y == n))
        return;

    for (int i = 0; i <= m; ++i)
    {
        h[x] = h[x] + i;
        l[y] = l[y] + i;
        if (h[x] > m || l[y] > m)
        {
            h[x] = h[x] - i;
            l[y] = l[y] - i;
            continue;
        }
        if (y == n)
        {
            if (h[x] != m)
            {
                h[x] = h[x] - i;
                l[y] = l[y] - i;
                continue;
            }

            dfs(x + 1, 1);
        }
        else
        {
            if (x == n)
            {
                if (l[y] != m)
                {
                    h[x] = h[x] - i;
                    l[y] = l[y] - i;
                    continue;
                }
            }
            dfs(x, y + 1);
        }
        h[x] = h[x] - i;
        l[y] = l[y] - i;
    }
}
void solve()
{
    cin >> m >> n;
    dfs(1, 1);
    cout << ans;
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