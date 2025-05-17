#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
const int N = 1e3 + 10;
const int M = 1e4 + 10;
i64 f[N][M]; // 能开这么大？？
struct node
{
    int t, b;
    i64 h;
} a[N], p[N];

bool cmp(node A, node B)
{
    return A.b < B.b;
}
void solve()
{
    int n, T;
    cin >> n >> T;

    for (int i = 0; i <= n + 1; ++i)
    {
        if (i && i <= n)
            cin >> a[i].t >> a[i].b >> a[i].h;
        else
            a[i].t = 0, a[i].b = 0, a[i].h = 0;
        // p[i].t = 0, p[i].b = 0, p[i].h = 0; // 是否有必要
    }

    sort(a + 1, a + n + 1, cmp);

    for (int i = n; i >= 1; --i) // 后缀背包
    {
        // for (int j = T; j >= p[i].t; --j)
        // {
        //     f[i][j] = max(f[i + 1][j], f[i + 1][j - p[i].t] + p[i].h);
        // }

        for (int j = T; j >= 0; --j)
        {
            if (j < a[i].t)
                f[i][j] = f[i + 1][j];
            else
            {
                f[i][j] = max(f[i + 1][j], f[i + 1][j - a[i].t] + a[i].h);
            }
        }
    }

    // i64 sum = 1; // 当前背包大小
    i64 ans = 0, bns = 0;
    int i = 1;
    // n = nn;
    for (int s = 1, sum = 1; s <= T; ++s, ++sum)
    {
        if (s == a[i].b)
        {
            while (s == a[i].b)
            {
                sum -= a[i].t;
                bns += a[i].h;
                i++;
            }

            if (sum < 0)
            {
                break;
            }

            ans = max(ans, bns + f[i][sum]);
            if (i == n + 1)
            {
                break;
            }
        }
        else
        {
            ans = max(ans, bns + f[i][sum]);
        }
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