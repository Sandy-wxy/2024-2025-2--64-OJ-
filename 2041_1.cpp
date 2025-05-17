#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
string a, b, c;

void solve()
{
    cin >> a >> b >> c;
    int m, n;

    m = (int)a.size() - 1;
    n = (int)b.size() - 1;
    // cout << dfs(m, n);

    auto dfs = [&](auto &&self, int m, int n) -> bool
    {
        if (m + n == -2)
            return true;
        int f1 = 0, f2 = 0;
        if (m != -1 && a[m] == c[m + n + 1])
            f1 = 1;
        if (n != -1 && b[n] == c[m + n + 1])
            f2 = 1;

        if (f1 && f2)
        {
            if (self(self, m - 1, n))
                return true;
            else if (self(self, m, n - 1))
                return true;
        }
        // return dfs(m - 1, n) + dfs(m, n - 1);
        else if (f1)
            return self(self, m - 1, n);
        else if (f2)
            return self(self, m, n - 1);
        else
            return false;

        return false;
    };

    if (dfs(dfs, m, n))
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
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

/*class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

    int m, n,t;

    m = (int)s1.size() - 1;
    n = (int)s2.size() - 1;
    t=(int)s3.size()-1;
      string a = s1, b = s2, c = s3;
    // cout << dfs(m, n);
 if (n + m +1!= t) {
            return false;
        }

    auto dfs = [&](auto &&self, int m, int n) -> bool
    {
        if (m + n == -2)
            return true;
        int f1 = 0, f2 = 0;
        if (m != -1 && a[m] == c[m + n + 1])
            f1 = 1;
        if (n != -1 && b[n] == c[m + n + 1])
            f2 = 1;

        if (f1 && f2)
        {
            if (self(self, m - 1, n))
                return true;
            else if (self(self, m, n - 1))
                return true;
        }
        // return dfs(m - 1, n) + dfs(m, n - 1);
        else if (f1)
            return self(self, m - 1, n);
        else if (f2)
            return self(self, m, n - 1);
        else
            return false;
    };

    return dfs(dfs,m,n);
}
};*/