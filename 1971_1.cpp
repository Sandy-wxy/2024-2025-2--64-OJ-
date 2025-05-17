#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int x, n;
    cin >> x >> n;

    vector<int> mp;

    long double ans = log10(x) + 1;
    mp.emplace_back((int)ans);

    for (int i = 1; ans < 100000; ++i)
    {

        ans += log10(x);

        if (i % 2 == 0)
            ans += log10(i);

        mp.emplace_back((int)ans);
    }
    int d;
    while (n--)
    {
        cin >> d;
        cout << upper_bound(mp.begin(), mp.end(), d) - mp.begin() << "\n";
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