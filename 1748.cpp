#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n;
const int N = 2e3 + 10;
map<int, int> mp1, mp2;
// vector<int> a[4];
int a[N][5];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            mp1[a[i][1] + a[j][2]]++;
            mp2[a[i][3] + a[j][4]]++;
        }
    }
    int ans = 0;
    for (auto [val, key] : mp1) // 数目 数字
    {
        // cout << key << " " << val << "\n";
        int t = val;
        t *= -1;
        ans += mp2[t] * key;
    }
    mp1.clear();
    mp2.clear();
    cout << ans << "\n";
}

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