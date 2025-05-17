#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int s[100005] = {0};
string Multiply(string a, string b)
{
    int m = a.size(), n = b.size();

    string ss = "0";
    if (m + n > 100005)
        return ss;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            s[i + j] += (a[m - i - 1] - '0') * (b[n - j - 1] - '0');
        }
    }

    for (int i = 0; i < m + n; ++i)
    {
        if (s[i] >= 10)
        {
            s[i + 1] += s[i] / 10;
            s[i] %= 10;
        }
    }
    int j = m + n; // 0-base;超点没事
    while (s[j] == 0)
        j--;
    string ans;
    for (int i = j; i >= 0; --i)
        ans.push_back(s[i] + '0');
    //
    if (ans.empty())
        ans = '0';
    return ans;
}

void solve()
{
    int x, n;
    cin >> x >> n;
    vector<int> mp;

    string s = to_string(x);
    mp.emplace_back((int)s.size());
    string xx = s;
    for (int i = 1; s.size() < 100000; ++i)
    {
        s = Multiply(s, xx);
        if (s == "0")
            break;
        string t = to_string(i);
        if (i % 2 == 0)
        {
            s = Multiply(s, t);
        }
        if (s == "0")
            break;
        mp.emplace_back((int)s.size());
    }

    // cout << 1 << "\n";
    int d;
    while (n--)
    {
        cin >> d;
        cout << upper_bound(mp.begin(), mp.end(), d) - mp.begin() << "\n";
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