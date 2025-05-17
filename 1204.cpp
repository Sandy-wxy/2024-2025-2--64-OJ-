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
    double s = 0;
    double z;
    if (n == 2)
    {
        double a, b;
        cin >> a >> b;
        cout << fixed << setprecision(1) << min(a, b);
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> z;
        s += z;
    }
    s /= 2;

    cout << fixed << setprecision(1) << s;
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