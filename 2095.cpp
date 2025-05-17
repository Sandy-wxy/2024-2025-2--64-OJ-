#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int a[105][105];
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if (a[i][j])
                cnt++;
        }
        if (cnt & 1)
            ans++;
    }
    if (ans == 0 || ans == 2)
        cout << "YES\n";
    else
        cout << "NO\n";
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