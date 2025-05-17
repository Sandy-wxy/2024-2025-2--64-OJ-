#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
string a, b;
int n;
void fun(int in, int pre, int len) // 中序 前序
{
    // in   in+len-1;
    int l = in + len - 1;
    int l1 = 0;
    int i;
    for (i = in; i <= l; ++i)
    {
        if (a[i] == b[pre])
        {
            break;
        }
        ++l1;
    }
    int l2 = len - l1 - 1;
    if (l1 > 0)
        fun(in, pre + 1, l1);
    if (l2 > 0)
        fun(i + 1, pre + l1 + 1, l2);
    cout << b[pre];
}

void solve()
{
    cin >> a >> b; // in中序· pre先序
    n = a.size();
    fun(0, 0, n);
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