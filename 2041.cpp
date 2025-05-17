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
    string a, b, c;
    cin >> a >> b >> c;
    int m = (int)a.size(), n = b.size();

    int pos1 = 0, pos2 = 0;
    int f1 = -1, f2 = -1, pos = -1, k = 0;
    for (int i = 0; i < (int)c.size(); ++i)
    {

        if (pos1 < m && a[pos1] == c[i])
        {
            //
            if (a[pos1] == b[pos2 + k])
            {
                if (k == 0)
                {
                    f1 = pos1;
                    f2 = pos2;
                    pos = i;
                }
                k++;
            }
            else
                k = 0;
            pos1++;
        }
        else if (pos2 < n && b[pos2] == c[i])
        {
            k = 0;
            pos2++;
        }
        else
        {
            if (k != 0)
            {
                i = pos;
                pos2 = f2;
                pos1 = f1;

                if (b[pos2] == c[i])
                {
                    pos2++;
                    k = 0;
                }
                else
                {
                    cout << "NO\n";
                    return;
                }
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}