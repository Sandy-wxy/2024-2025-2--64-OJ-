#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    i64 x, y;
    cin >> x >> y;
    i64 s;
    cin >> s;
    i64 l = x, r = y;
    while (l <= r)
    {
        i64 mid = l + r >> 1;
        if (mid > s)
        {
            cout << 'L';
            r = mid - 1;
        }
        else if (mid == s)
        {
            cout << "G";
            return;
        }
        else
        {
            cout << "R";
            l = mid + 1;
        }
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