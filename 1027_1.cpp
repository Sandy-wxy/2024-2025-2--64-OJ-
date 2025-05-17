
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int m;
void solve()
{
    cin >> m;
    //
    int sum;
    int k = m + 1;
    while (1)
    {
        sum = m * 2;
        int ins = 0; // 报数的位置
        for (int i = 0; i < m; ++i)
        {
            ins = (ins + k - 1) % sum;
            if (ins < m)
                break;
            --sum;
        }
        if (sum == m)
        {
            cout << k;
            return;
        }
        k++;
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