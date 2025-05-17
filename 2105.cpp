#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
const int N = 2e5 + 10;
i64 a[N];
i64 n, v;
i64 ans = 0;

bool check(int mid)
{
    //
    if (mid == 0)
        return true;
    int t;
    for (int i = 0; i + mid - 1 < n; i++)
    {
        t = 0;
        for (int j = 0; j < mid; ++j) // i+mid-1<=m-1
        {
            t += a[i + j];
        }
        if (t <= v)
            return true;
    }
    return false;
}
void solve()
{
    cin >> n >> v;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    i64 l = 0, r = n;
    while (l < r)
    {
        i64 mid = (l + r + 1) >> 1;
        if (check(mid))
        {
            // xiaode
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l;
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