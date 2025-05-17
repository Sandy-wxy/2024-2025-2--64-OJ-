#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define endl '\n'
typedef struct node
{
    int t, b, h;
} node;
node a[1005];
bool cmp(const node &x, const node &y)
{
    return x.b > y.b;
}
int n, T;
ll ans;
ll dp[1005][10004];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> T;
    for (int i = 1; i <= n; i++)
        cin >> a[i].t >> a[i].b >> a[i].h;
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = T; j >= 0; j--)
        {
            if (j - a[i].t >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].t] + a[i].h);
            // cout<<dp[i][j]<<" ";
            else
                dp[i][j] = dp[i - 1][j];
        }
        // cout<<endl;
    }
    ans = -1;
    for (int i = 1; i <= T; i++)
    {
        int s = 0;
        ll v = 0;
        bool ok = 1;
        int j;
        for (j = n; a[j].b <= i && j >= 1; j--)
        {
            s += a[j].t;
            v += a[j].h;
            if (s > i)
            {
                ok = 0;
                j--;
                break;
            }
        }
        if (ok == 1)
        {
            ans = max(ans, v + dp[j][i - s]);
        }
        else
            break;
    }
    cout << ans;
    return 0;
}