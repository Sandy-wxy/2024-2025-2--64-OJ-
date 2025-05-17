#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;

struct DSU
{
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n + 1); // 有时候虚树要2*n+1
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n + 1, 1); // 有时候虚树要2*n+1
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) // da
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
const int N = 2e6;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    DSU s(N);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (mp[a[i]])
        {
            a[i] = s.find(a[i]) + 1;
            mp[a[i]] = 1;
        }
        else
            mp[a[i]] = 1;

        if (mp[a[i] + 1])
        {
            s.merge(a[i] + 1, a[i]);
        }
        if (mp[a[i] - 1])
        {
            s.merge(a[i], a[i] - 1);
        }
    }

    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
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