#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
struct node
{
    int l, r;
    i64 dis;
    i64 ll, rr;
};
void solve()
{
    int n;
    i64 m;
    cin >> n >> m;
    vector<pair<i64, i64>> a(n);
    set<i64> s; // hash_set 但是可能冲突 数值哈希
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second >> a[i].first;
        a[i].first += a[i].second;
        s.insert(a[i].first);
        s.insert(a[i].second);
    }

    sort(a.begin(), a.end());

    map<i64, int> mp;
    vector<i64> d;
    int ins = 0;
    i64 pre = 0;
    d.push_back(0);
    for (auto v : s)
    {
        ins++;
        mp[v] = ins;          // 1
        d.push_back(v - pre); // 0 1
        pre = v;
    }

    vector<i64> dp(ins + 1, 0);
    vector<node> b(n);
    for (int i = 0; i < n; i++)
    {
        b[i].l = mp[a[i].second];
        b[i].r = mp[a[i].first];
        b[i].dis = a[i].first - a[i].second;
        b[i].ll = a[i].second;
        b[i].rr = a[i].first;

        // 对于lr l2 r2
        // 使用该区间 l旁边一定有一个r 一定是从r走过来的
        // 不使用该区间 从上一个r走过来  我离散化的目的不就是每个距离点过一遍吗！！！
    }

    i64 ans = 0;
    pre = m;
    for (int i = n - 1; i >= 0; --i)
    {
        if (b[i].rr < pre)
        {
            ans += (-b[i].rr + pre);
        }
        pre = min(pre, b[i].ll);
    }
    if (pre > 0ll)
    {
        ans += pre;
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