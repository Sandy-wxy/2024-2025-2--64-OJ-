#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
const int MAXN = 3000;
struct edge
{
    int v, w;
};

struct node
{
    i64 dis, u;

    bool operator>(const node &a) const { return dis > a.dis; }
};

int vis[MAXN];
vector<edge> e[MAXN], e1[MAXN];
i64 dis0[MAXN], dis1[MAXN];

void dijkstra(int n, int s, i64 dis[], vector<edge> e[]) // dis0 和 dis1 数组可以被 dijkstra 函数修改，是因为 数组作为函数参数时实际上传递的是指针，而不是值拷贝
{
    priority_queue<node, vector<node>, greater<node>> q;

    memset(dis, 0x3f, (n + 1) * sizeof(i64));
    memset(vis, 0, (n + 1) * sizeof(i64));
    dis[s] = 0;

    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().u;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

void solve()
{

    int n, m, s;
    cin >> n >> m >> s;
    int u, v, w;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w;
        e[u].push_back({v, w});  // dis[u]
        e1[v].push_back({u, w}); // dis[u]
    }

    dijkstra(n, s, dis0, e);
    dijkstra(n, s, dis1, e1);

    i64 ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, dis0[i] + dis1[i]);
    }
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