#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
int w[105], t[1005]; // 注意范围
int dp[1005];        // 容量这么大 最大的价值
void solve()
{
    int T, n;
    cin >> T >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i] >> w[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = t[i]; j <= T; ++j)
        {
            dp[j] = max(dp[j], dp[j - 1]);
            dp[j] = max(dp[j], dp[j - t[i]] + w[i]); // 显然不严谨，因为你在更新答案的时候，极有可能选中多个相同物体
        }
    }

    cout << dp[T];
}
// int dp[105][1005];
// void solve()
// {
//     int T, n;      //
//     cin >> T >> n; // V n
//     for (int i = 1; i <= n; ++i)
//         cin >> t[i] >> w[i];

//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = 1; j <= T; ++j) // 必须从1开始，不能从t[i],相当于每个点都走一遍，每次更新每个点的答案，要么和前面的一样，要么加上这个物体
//         {
//             dp[i][j] = dp[i - 1][j];
//             if (j - t[i] >= 0) // 注意判断
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - t[i]] + w[i]);
//         }
//     }
//     cout << dp[n][T];
// }

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