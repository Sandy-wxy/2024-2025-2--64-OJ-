#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
using namespace std;
using namespace tr2;
using i64 = long long;
string a, b, c;
int m, n, s;
int n1, n2, n3;
string a1, a2, a3;
// bool dfs(int i, int j, int k)
// {

//     if (i >= n1 || j >= n2 || k >= n3)
//         return false;
//     if (i == n1 - 1 && j == n2 - 1 && k == n3 - 1)
//         return true;
//     bool r1 = 0, r2 = 0;
//     if (a1[i + 1] == a3[k + 1])
//     {
//         r1 = dfs(i + 1, j, k + 1);
//         if (r1)
//         {
//             //            cout<<i<<" "<<j<<" "<<k<<" "<<r1<<endl;
//             return r1;
//         }
//     }
//     if (a2[j + 1] == a3[k + 1])
//     {
//         r2 = dfs(i, j + 1, k + 1);
//         if (r2)
//         {
//             //            cout<<i<<" "<<j<<" "<<k<<" "<<r2<<endl;
//             return r2;
//         }
//     }
//     //    cout<<i<<" "<<j<<" "<<k<<" "<<(r1|r2)<<endl;
//     return r1 | r2;
// }
bool dfs(int i, int j, int k)
{
    if (i >= m || j >= n || k >= s)
        return false;
    if (i == m - 1 && j == n - 1 && k == s - 1)
        return true;

    bool r1 = 0, r2 = 0; //
    if (a[i + 1] == c[k + 1])
    {
        r1 = dfs(i + 1, j, k + 1);
        if (r1)
        {

            return r1;
        }
    }

    if (b[j + 1] == c[k + 1])
    {
        r2 = dfs(i, j + 1, k + 1);
        if (r2)
        {

            return r2;
        }
    }
    return r1 | r2;
}

void solve()
{
    cin >> a >> b >> c;
    a1 = a, a2 = b, a3 = c;

    n1 = a.size(), n2 = b.size(), n3 = c.size();

    m = (int)a.size();
    n = (int)b.size();
    s = (int)c.size();
    if (dfs(-1, -1, -1))
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