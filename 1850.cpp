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
    vector<int> a(n + 1), pre(n + 2, 1), suf(n + 2, 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[j] > a[i])
            {
                pre[j] = max(pre[j], pre[i] + 1);
            }
        }
    }

    for (int i = n; i >= 1; --i)
    {
        for (int j = i - 1; j >= 1; --j)
        {
            if (a[j] > a[i])
            {
                suf[j] = max(suf[j], suf[i] + 1);
            }
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, pre[i] + suf[i] - 1);
    }
    cout << n - ans;
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