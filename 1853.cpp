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
    int m, s, t;
    cin >> m >> s >> t;

    int ans = 0, s1 = 0, s2 = 0, bns = 0;

    while (((m / 10) && t > 0) || (((10 - m % 10 + 3) / 4 + 1 <= t) && t > 0))
    {
        if (m / 10)
        {
            ans++;
            t--;
            s1 += 60;
            m -= 10;
            if (s1 >= s)
            {
                cout << "Yes\n";
                cout << ans;
                return;
            }
            continue;
        }
        s2 = s1;
        bns = ans;

        int i = (10 - m % 10 + 3) / 4 + 1; // 向上取整 所需要的时间

        for (int j = i; j >= 1; --j)
        {
            s2 += 17;
            bns++;
            if (s2 >= s)
            {
                cout << "Yes\n";
                cout << bns;
                return;
            }
        }

        ans += i;
        t -= i;
        s1 += 60;
        m += (i - 1) * 4;
        m -= 10;
        if (s1 >= s)
        {
            cout << "Yes\n";
            cout << ans;
            return;
        }
    }

    s2 = s1;
    bns = ans;

    for (t; t >= 1; --t)
    {
        s2 += 17;
        bns++;
        if (s2 >= s)
        {
            cout << "Yes\n";
            cout << bns;
            return;
        }
    }

    cout << "No\n";
    cout << s2;
    // int ans = min(m / 10, t);
    // int ss = min(m / 10, t) * 60;
    // int tt = t - min(t, m / 10);
    // int mm = m % 10 + (m / 10 - min(t, m / 10)) * 10;

    // if (s <= ss)
    // {
    //     cout << "Yes\n";
    //     ans = s / 60 + (s % 60 != 0);
    //     cout << ans;
    //     return;
    // }

    // // ss<s
    // while (4ll * tt >= (10 - mm % 10))
    // {
    //     t = max((10 - mm % 10 + 3) / 4 - 1, 1);
    //     int sss = ss + t * 17;
    //     if (sss >= s)
    //     {
    //         cout << "Yes\n";
    //         cout << ans + t;
    //         return;
    //     }

    //     ans += (10 - mm % 10 + 3) / 4;
    //     tt -= (10 - mm % 10 + 3) / 4;
    //     mm += (10 - mm % 10 + 3) * 4;
    //     ss += mm / 10 * 60;
    //     mm = mm % 10;
    //     if (ss >= s)
    //     {
    //         cout << "Yes\n";
    //         cout << ans;
    //         return;
    //     }
    // }

    // while (tt)
    // {
    //     ans++;
    //     tt--;
    //     ss += 17;
    //     if (ss >= s)
    //     {
    //         cout << "Yes\n";
    //         cout << ans;
    //         return;
    //     }
    // }

    // cout << "No\n";
    // cout << ss;
    // return;
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