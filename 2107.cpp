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
    int ans = 0, bns = 0;
    vector<pair<int, int>> a(n + 1);
    vector<int> pre(1002, 0);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        pre[a[i].first]++;
        pre[a[i].second + 1]--;
    }
    for (int i = 1; i <= 1000; ++i)
    {
        bns += pre[i];
        ans = max(ans, bns);
    }
    cout << ans;
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