#include <iostream>
using namespace std;
int nums[1000000];
int main()
{
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int preDiff = 0;
    int curDiff = 0;
    int result = 1; // 长度为2，即使是两个数字相等，子序列长度也有一个
    for (i = 1; i < n; i++)
    {
        curDiff = nums[i] - nums[i - 1];
        // 计算当前位置的变化方向
        if ((curDiff < 0 && preDiff >= 0) || (curDiff > 0 && preDiff <= 0))
        {
            // 如果当前位置和前方位置的变化方向相反
            // 序列长度加1，并记录变化方向
            result++;
            preDiff = curDiff;
        }
    }
    cout << n - result << endl;
    return 0;
}

// #include <bits/stdc++.h>
// #include <tr2/dynamic_bitset>
// #define rep(i, from, to) for (i = (from); i <= (to); i++)
// #define per(i, from, to) for (i = (from); i >= (to); i--)
// #define equal ==
// using namespace std;
// using namespace tr2;
// using i64 = long long;

// void solve()
// {
//     int ans = 0;
//     int n;
//     cin >> n;
//     int f = -1;
//     int pre = 0;

//     vector<int> a(n);
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> a[i];
//         if (pre != 0)
//         {
//             if (a[i] > pre)
//             {
//                 if (f == -1)
//                 {
//                     ans++;
//                     f = 1;
//                     pre = a[i];
//                 }
//                 else if (f == 0)
//                 {
//                     ans++;
//                     f = 1;
//                     pre = a[i];
//                 }
//                 else
//                     pre = a[i];
//             }
//             else if (a[i] < pre)
//             {
//                 if (f == -1)
//                 {
//                     ans++;
//                     f = 0;
//                     pre = a[i];
//                 }
//                 else if (f == 1)
//                 {
//                     ans++;
//                     f = 0;
//                     pre = a[i];
//                 }
//                 else
//                     pre = a[i];
//             }
//         }
//         else
//         {
//             pre = a[i];
//             ans++;
//         }
//     }

//     cout << n - ans;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int _ = 1;
//     // cin>>_;
//     while (_--)
//     {
//         solve();
//     }
//     return 0;
// }