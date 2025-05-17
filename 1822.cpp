#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    int u, v;
    int mx = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> u >> v;
        mx = max(mx, u);
        mx = max(mx, v);
    }
    // cout << ((int)log2(n + 2) - 1);
    // cout << mx;
    int ans = (int)log2(mx);
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