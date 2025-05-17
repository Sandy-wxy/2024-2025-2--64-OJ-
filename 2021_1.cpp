#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
const int N = 1e3 + 10, M = 1e2 + 10;
int dp[N][M]; // 在i位置使用j的卡皮巴拉
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            int k = i - m - m - 1;
            if (k >= 1)
            {
                dp[i][j] = dp[k][j - 1];
            }
            int r = min(n, i + m);
            int l = max(0, i - m - 1);
            dp[i][j] += pre[r] - pre[l];
            dp[i][j] = max(dp[i][j], dp[i - 1][j]); // 不选当前的 使用卡皮巴拉
        }
    }
    cout << dp[n][k];

    // int ans = 0;
    // for (int i = 1; i <= n; ++i)
    // {
    //     int k = i - m - m - 1;
    //     int kk = i - m - 1;
    //     int s = i + m;
    //     s = min(n, s);

    //     for (; k >= 1; --k)
    //     {
    //         for (int j = 1; j <= k && j <= i; ++j)
    //         {
    //             dp[i][j] = dp[k][j - 1] + pre[s] - pre[kk];
    //             ans = max(ans, dp[i][j]);
    //         }
    //     }
    // }
    // cout << ans;
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