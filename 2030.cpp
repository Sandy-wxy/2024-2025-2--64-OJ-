#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;

const int N = 105;

int g[N][N], n, m;
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void solve()
{
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = 1e9;
        }
    }

    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    floyd();
    i64 ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (i == 2)
        {
            ans += g[1][2];
            ans += a[i];
        }
        else
        {
            ans += min(a[i - 1] + g[i - 1][i], g[i - 1][1] + g[1][i]);
            ans += a[i];
        }
    }
    ans += g[n][1];
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