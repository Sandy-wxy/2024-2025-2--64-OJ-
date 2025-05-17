#include <bits/stdc++.h>
#define endl "\n"
#define x first
#define y second
#define no cout << "No" << endl
#define yes cout << "Yes" << endl

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int N = 10010;
const int inf = 0x3f3f3f3f;
const ll lnf = 1e18;

ll f[N][N];
int T, n, m, k;
int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};

struct node
{
    ll t, b, h;

    bool operator<(const node &a) const
    {
        if (a.b != b)
            return b < a.b;
    }

} a[N];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].t >> a[i].b >> a[i].h;
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--)
    {
        // cout << a[i].t << ' ' << a[i].b << ' ' << a[i].h << '\n';

        for (int j = m; j >= a[i].t; j--)
            f[i][j] = max(f[i + 1][j], f[i + 1][j - a[i].t] + a[i].h);
        // for (int j = 1; j <= m; j++)
        // {
        //     cout << f[i][j] << ' ';
        // }
        // cout << endl;
    }

    ll sum = 0, happy = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, happy + f[i][sum + a[i].b - a[i - 1].b - 1]);
        sum += a[i].b - a[i - 1].b;
        sum -= a[i].t;
        if (sum < 0)
        {
            break;
        }
        happy += a[i].h;
        // cout << ans << ' ' << happy + f[i+1][sum] << ' ' << sum << endl;
        ans = max(ans, happy + f[i + 1][sum]);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}