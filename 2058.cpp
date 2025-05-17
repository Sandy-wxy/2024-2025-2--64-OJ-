#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 10;
struct node
{
    int i, j, c;
} a[N];
bool cmp(node a, node b)
{
    return a.c < b.c;
}
void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].i >> a[i].j >> a[i].c;
    }

    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i].i << " " << a[i].j << " " << a[i].c << "\n";
    }
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