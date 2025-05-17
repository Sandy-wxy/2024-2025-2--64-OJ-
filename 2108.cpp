#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
const int N = 2e5 + 10;
i64 dp[N][2]; // 0 1变或者 +1
void solve()
{
    // 2 1 1 2
    int n;
    cin >> n;
    vector<i64> a(n + 1), c(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    for (int i = 0; i < n; ++i)
    {
        if (i)
        {
            int pre = a[i - 1];
            int aft = a[i - 1] + 1;
            if (pre != a[i] && aft != a[i])
            {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
            }
            else if (pre != a[i])
            {
                dp[i][0] = dp[i - 1][0];
            }
            else
                dp[i][0] = dp[i - 1][1];

            if (pre != a[i] + 1 && aft != a[i] + 1)
            {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] += c[i];
            }
            else if (pre != a[i] + 1)
            {
                dp[i][1] = dp[i - 1][0];

                dp[i][1] += c[i];
            }
            else
            {
                dp[i][1] = dp[i - 1][1];
                dp[i][1] += c[i];
            }
        }
        else
        {
            dp[i][0] = 0;
            dp[i][1] = c[i];
        }
    }

    cout << min(dp[n - 1][0], dp[n - 1][1]);
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