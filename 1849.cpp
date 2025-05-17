#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
int dp[55][55][55][55];
int b[] = {0, 0, 0, 0, 0};
void solve()
{
    int n, m;
    cin >> n >> m;
    // 120!状压dp？

    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1, z; i <= m; ++i)
    {
        cin >> z;
        b[z]++;
    }

    for (int i = 0; i <= b[1]; ++i)
    {
        for (int j = 0; j <= b[2]; ++j)
        {
            for (int k = 0; k <= b[3]; ++k)
            {
                for (int s = 0; s <= b[4]; ++s)
                {
                    dp[i][j][k][s] = -1;
                }
            }
        }
    }

    dp[0][0][0][0] = a[1];

    for (int i = 0; i <= b[1]; ++i)
    {
        for (int j = 0; j <= b[2]; ++j)
        {
            for (int k = 0; k <= b[3]; ++k)
            {
                for (int s = 0; s <= b[4]; ++s)
                {
                    int now = 1 + i * 1 + j * 2 + k * 3 + s * 4;
                    if (now - 1 >= 1 && i - 1 >= 0 && dp[i - 1][j][k][s] != -1)
                    {
                        dp[i][j][k][s] = max(dp[i][j][k][s], dp[i - 1][j][k][s] + a[now]);
                    }
                    if (now - 2 >= 1 && j - 1 >= 0 && dp[i][j - 1][k][s] != -1)
                    {
                        dp[i][j][k][s] = max(dp[i][j][k][s], dp[i][j - 1][k][s] + a[now]);
                    }
                    if (now - 3 >= 1 && k - 1 >= 0 && dp[i][j][k - 1][s] != -1)
                    {
                        dp[i][j][k][s] = max(dp[i][j][k][s], dp[i][j][k - 1][s] + a[now]);
                    }
                    if (now - 4 >= 1 && s - 1 >= 0 && dp[i][j][k][s - 1] != -1)
                    {
                        dp[i][j][k][s] = max(dp[i][j][k][s], dp[i][j][k][s - 1] + a[now]);
                    }
                }
            }
        }
    }

    cout << dp[b[1]][b[2]][b[3]][b[4]];
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