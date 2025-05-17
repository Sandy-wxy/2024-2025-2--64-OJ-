#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;

const int M = 25e6 + 1, N = 5e3 + 1;
struct Edge
{
    int u, v;
    i64 w;
    bool operator<(const Edge &rhs) const
    {
        return w < rhs.w;
    }
} edge[M];
int fa[N], n, m; // n 为点数 m 为边数
int find(int x)
{
    while (fa[x] != x)
        x = fa[x] = fa[fa[x]];
    return x;
}
i64 kruskal()
{
    sort(edge, edge + m); // 边存储为 [0, m - 1] 区间
    iota(fa, fa + n, 0);
    i64 sum = 0, cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        int u = edge[i].u, v = edge[i].v;
        i64 w = edge[i].w;
        u = find(u), v = find(v);
        if (u != v)
        {
            fa[u] = v;
            sum = max(sum, w);
            ++cnt;
        }
    }
    // return cnt == n - 1; // 判断是否能构成最小生成树
    return sum; // 返回最小生成树边权和 注意改成int
}

// 存点，编号，然后把边存进edge
struct node
{
    int x, y;
} e[N];

void solve()
{
    cin >> n;
    m = n * (n - 1) / 2;

    for (int i = 1; i <= n; ++i)
    {
        cin >> e[i].x >> e[i].y;
    }

    int ins = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            i64 w = (1ll * (e[i].x - e[j].x) * (e[i].x - e[j].x) + (1ll * (e[i].y - e[j].y) * (e[i].y - e[j].y)));

            edge[ins].u = i, edge[ins].v = j, edge[ins].w = w;
            ins++;
        }
    }

    i64 ans = kruskal();
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}