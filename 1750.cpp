#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
inline int lowbit(int x) { return x & (-x); }
int n;
const int N = 5e5 + 10;
int a[N];
struct node
{
    int ins, jns; // 原序  正序
    int num;      // 数字
} b[N];
void add(int p, int x)
{
    for (int i = p; i <= n; i += lowbit(i))
        a[i] += x;
}

i64 count(int p)
{
    i64 ans = 0;
    for (int i = p; i > 0; i -= lowbit(i))
    {
        ans += a[i];
    }
    return ans;
}

bool cmp_j(node a, node b)
{
    return a.num < b.num;
}
bool cmp_i(node a, node b)
{
    return a.ins < b.ins;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i].num;
        b[i].ins = i;
    }
    // 离散化
    sort(b + 1, b + n + 1, cmp_j);
    for (int i = 1; i <= n; ++i)
    {
        b[i].jns = i;
    }
    sort(b + 1, b + n + 1, cmp_i);

    i64 ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        add(b[i].jns, 1);
        ans += (i - count(b[i].jns));
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