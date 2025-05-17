#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 dp[100][100];
void init(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (int j = 1; j < i; ++j)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << dp[n][m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin>>_;
    init(20);
    while (_--)
    {
        solve();
    }
    return 0;
}