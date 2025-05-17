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
    vector<int> a(n), dp(n + 4, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = n - 1; i >= 0; --i)
    {
        dp[i] = max(dp[i + 2], dp[i + 3]);
        dp[i] += a[i];
    }
    cout << max(dp[0], dp[1]);
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