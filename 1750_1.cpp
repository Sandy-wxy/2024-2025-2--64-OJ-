#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 10;
int n;
int a[N];

inline int lowbit(int x) { return x & (-x); }
void add(int p, int x)
{
    for (int i = p; i <= n; i += lowbit(i))
        a[i] += x;
}
i64 count(int p)
{
    i64 ans = 0;
    for (int i = p; i > 0; i -= lowbit(i))
        ans += a[i];
    return ans;
}

struct node
{
    int ins; // 原序
    int jns; // 排序后序列
    int num; // 数字
} b[N];

bool cmp(node a, node b)
{
    return a.num < b.num;
}
bool cmp_i(node a, node b)
{
    return a.ins < b.ins;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i].num;
        b[i].ins = i;
    }
    sort(b + 1, b + n + 1, cmp);
    // 离散化
    for (int i = 1; i <= n; ++i)
        b[i].jns = i;
    sort(b + 1, b + n + 1, cmp_i);

    i64 ans = 0;
    // 树状数组操作
    for (int i = 1; i <= n; ++i)
    {
        add(b[i].jns, 1);
        ans += (i - count(b[i].jns));
    }
    cout << ans << "\n";
}