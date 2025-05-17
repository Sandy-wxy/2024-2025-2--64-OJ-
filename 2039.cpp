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
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    deque<int> q;
    for (int i = 0; i < n; ++i)
    {
        q.push_front(a[i]); // da dao xiao
    }

    int ans = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop_front();
        int s = 0;
        if (!q.empty())
            s = q.back();
        if (t + s <= w)
        {
            if (!q.empty())
                q.pop_back();
        }

        ans++;
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