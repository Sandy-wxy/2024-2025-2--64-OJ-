#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define mk make_pair
#define fi first
#define se second
#define y1 asdfasd
#define y0 adsfasdf
using namespace std;
using namespace tr2;
using i64 = long long;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const double PI = acos(-1.0);
bool check(i64 n) // 检查n是否为2的整数幂
{
    return (n & (n - 1)) == 0ll;
}
void solve()
{
    // 1 2 4 8 16
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n + 1);
    i64 t = 0;
    for (i64 i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] == k)
        {
            if (check(i))
            {
                t++;
            }
            else
            {
                //
                i64 res = (1ll << __lg(i)); // 返回整数 ==(int)log2(i)
                // cout << res << " res";
                res = i - res; //
                if (res <= t)
                {
                    t++;
                }
                else
                {
                    res -= t;
                    t += res;
                    t++;
                }
            }
        }
        // cout << t << " ";
    }
    cout << t;
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