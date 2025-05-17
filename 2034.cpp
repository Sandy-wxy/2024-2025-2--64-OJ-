#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int b;
    while (m--)
    {
        cin >> b;
        cout << upper_bound(a.begin(), a.end(), b) - a.begin() << "\n";
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