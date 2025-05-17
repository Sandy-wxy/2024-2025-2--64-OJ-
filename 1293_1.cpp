#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
int m, n; // m水果 n盘子
int ans = 0;
void dfs(int ins, int pre, int bns)
{
    if (ins == n + 1)
    {
        if (bns == m)
        {
            ans++;
        }
        return;
    }

    for (int i = pre; i + bns <= m; ++i)
    {
        dfs(ins + 1, i, bns + i);
    }
}
void solve()
{
    cin >> m >> n;
    dfs(1, 0, 0);
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