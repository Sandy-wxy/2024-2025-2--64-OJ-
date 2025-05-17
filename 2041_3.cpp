#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
string a, b, c;
const int N = 1e3 + 10;
void solve()
{
    cin >> a >> b >> c;
    int m, n, s;
    m = a.size();
    n = b.size();
    s = c.size();

    if (m + n != s)
    {
        cout << "NO\n";
        return;
    }
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i > 0 && a[i - 1] == c[i + j - 1])
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            }

            if (j > 0 && b[j - 1] == c[i + j - 1])
            {
                dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
    }

    if (dp[m][n])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
// bool dp[N][N];
// void solve()
// {
//     cin >> a >> b >> c;
//     int m, n, s;
//     m = (int)a.size() - 1;
//     n = (int)b.size() - 1;
//     s = (int)c.size() - 1;
//     if (m + n != s)
//     {
//         cout << "NO\n";
//         return;
//     }
//     for (int i = 0; i <= m + 1; ++i)
//     {
//         for (int j = 0; j <= n + 1; ++j)
//             dp[i][j] = false;
//     }
//     // dp[0][0] = true;
//     for (int i = 0; i <= m; ++i)
//     {
//         for (int j = 0; j <= n; ++j)
//         {
//             if(i==0&&j==0)
//             {
//                 dp[i][j]=
//             }
//             if (i)
//                 dp[i][j] |= (dp[i - 1][j] && a[i] == c[i + j + 1]);

//             if (j)
//                 dp[i][j] |= (dp[i][j - 1] && b[j] == c[i + j + 1]);
//         }
//     }

//     if (dp[m][n])
//         cout << "YES\n";
//     else
//         cout << "NO\n";
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}