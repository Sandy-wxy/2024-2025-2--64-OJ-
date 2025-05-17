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
    vector<i64> a(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    i64 mx = -1e18;
    for (int i = 1; i <= n; ++i)
    {
        mx = max(mx, a[i]);
        i64 pre = dp[i - 1] + a[i];
        if (pre >= a[i])
        {
            dp[i] = pre;
        }
        else
        {
            dp[i] = a[i];
        }

        mx = max(mx, dp[i]);
    }
    cout << mx;
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