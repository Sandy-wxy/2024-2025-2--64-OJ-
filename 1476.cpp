#include <iomanip>
#include <iostream>
#include <cstdio>
#include <ratio>
#include <string>
#include <string.h>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <tr2/dynamic_bitset>
#define rep(i, from, to) for (i = (from); i <= (to); i++)
#define per(i, from, to) for (i = (from); i >= (to); i--)
#define equal ==
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define TII tuple<int, int, int>
#define mk make_pair
#define fi first
#define se second
#define y1 asdfasd
#define y0 adsfasdf
#define FOR for (int i = 0; i < n; ++i)
using namespace std;
using namespace tr2;
using i64 = long long;
using ld = long double;
using ull = unsigned long long;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const double PI = acos(-1.0);
bool cmp(PII a, PII b)
{
    if ((a.se - a.fi >= 0) || (b.se - b.fi >= 0))
        return (a.se - a.fi) > (b.se - b.fi);
    return a.fi < b.fi;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int mi_a = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fi;
        mi_a = min(mi_a, a[i].fi);
    }
    int mi = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].se;
        mi = min(a[i].se, mi);
    }
    // sort(a.begin(), a.end(), cmp);
    i64 ans = 0, bns = 0, res = 0;
    for (int i = 0; i < n; ++i)
    {

        ans += a[i].fi;
        bns += a[i].se;
    }
    if (ans > bns)
    {
        cout << ans + mi;
    }
    else
    {
        cout << bns + mi_a; //
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}