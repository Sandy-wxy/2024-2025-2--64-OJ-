#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
const int N = 1e7 + 10;
int dp[N];
void init()
{
    for (int i = 0; i <= 1e7; ++i)
    {
        string s = to_string(i);
        int f = 1;
        for (int j = 0; j < (int)s.size(); ++j)
        {
            if (s[j] == '4')
            {
                f = 0;
                break;
            }
            if (j)
            {
                if (s[j - 1] == '6' && s[j] == '2')
                {
                    f = 0;
                    break;
                }
            }
        }
        if (i)
            dp[i] = dp[i - 1];
        if (f)
            dp[i]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 l, r;
    cin >> l >> r;
    init();
    while (l != 0 || r != 0)
    {
        if (l != 0)
            cout << dp[r] - dp[l - 1] << "\n";
        else
            cout << dp[r] << "\n";
        cin >> l >> r;
    }
    return 0;
}