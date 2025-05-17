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
    int t, b;
    i64 h;
};

bool cmp(node aa, node bb)
{
    if (aa.b == bb.b)
    {
        if (aa.t == bb.t)
        {
            return aa.h > bb.h;
        }
        return aa.t < bb.t;
    }
    return aa.b < bb.b;
}
void solve()
{
    int n, T;
    cin >> n >> T;
    vector<node> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].t >> p[i].b >> p[i].h;
    }

    // 0 1 2

    sort(p.begin(), p.end(), cmp);

    int t = 0;
    i64 ans = 0;

    // 暂时假设不会有一样的截止过期时间->WA
    for (int i = 0; i < n; ++i)
    {
        t += p[i].t;

        i64 bns = 0;
        bns += p[i].h;
        while (i != n - 1 && p[i + 1].b == p[i].b)
        {
            t += p[i + 1].t;
            bns += p[i + 1].h;
            i++;
        }
        if (t > T || t > p[i].b)
        {
            cout << ans;
            return;
        }

        ans += bns;
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