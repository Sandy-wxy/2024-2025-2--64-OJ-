#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
int ans = 0;
int m, n;

void dfs(int ins, int cnt, int bns)
{
    cout << ins << " " << cnt << " " << bns << "\n";

    if (ins == n + 1)
    {

        if (bns == m)
        {
            ans++; // 7 6 5 4 3
            cout << cnt << "ooooooooooooook\n";
        }
        return;
    }

    for (int i = cnt; bns + i <= m; ++i)
    {
        dfs(ins + 1, i, bns + i);
    }
}
void solve()
{
    cin >> m >> n;
    dfs(0, 0, 0);
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