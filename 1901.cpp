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
    vector<int> a(n), dp(n + 2, 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int mx = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (gcd(a[i], a[j]) == 1)
            {
                dp[j] = max(dp[j], dp[i] + 1);
                mx = max(mx, dp[j]);
            }
        }
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