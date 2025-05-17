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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // sort(a.rbegin(), a.rend());
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; ++i)
    {
        if (i < m)
            q.push(a[i]);
        else
        {
            int t = q.top();
            t += a[i];
            q.pop();
            q.push(t);
        }
    }
    for (int i = 0; i < m - 1; ++i)
        q.pop();
    cout << q.top();
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