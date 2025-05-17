#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 10;
map<i64, int> mp;
i64 a[N], b[N];
void solve()
{
    i64 x, y, z;
    cin >> x >> y >> z;
    i64 n;
    cin >> n;

    for (int i = 0; i < z; ++i)
    {
        if (i == 0)
            b[i] = x;
        else if (i == 1)
            b[i] = y;
        else
            b[i] = b[i / 2] + b[i / 4];
    }
    for (int i = 0; i < z; ++i)
    {
        if (!mp[b[i]])
            mp[b[i]] = i + 1;
    }
    for (int i = 1, s; i <= n; ++i)
    {
        cin >> s;
        if (mp[s])
            a[i] = mp[s] - 1;
        else
            a[i] = -1;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << "\n";
    }
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