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
    int n;
    cin >> n;

    int jj = 0, oo = 0, jo = -1, oj = -1; // 偶 奇
    for (int i = 0, z; i < n; ++i)
    {
        cin >> z;
        if (z & 1)
        {
            jj++;
            if (jo != -1)
            {
                oj = jo + 1;
            }
            else
                oj = 1;
        }
        else
        {
            oo++;
            if (oj != -1)
            {
                jo = oj + 1;
            }
            else
                jo = 1;
        }
    }
    cout << max(jo, oj) - max(jj, oo);
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