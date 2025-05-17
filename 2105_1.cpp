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
    i64 n, v;
    cin >> n >> v;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    i64 l = 0;
    i64 t = 0, ans = 0;

    for (int i = 0; i < n; ++i)
    {
        t += a[i];
        while (t > v && l <= i)
        {
            t -= a[l];
            l++;
        }
        if (t > v)
        {
            t = 0;
        }
        ans = max(ans, t);
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