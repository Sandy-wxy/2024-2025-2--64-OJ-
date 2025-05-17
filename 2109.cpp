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
    i64 x;
    cin >> x;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.rbegin(), a.rend());

    int cnt = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] * cnt >= x)
        {
            ans++;
            cnt = 1;
        }
        else
            cnt++;
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