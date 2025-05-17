#include <bits/stdc++.h>
#define endl "\n"
#define x first
#define y second
#define no cout << "No" << endl
#define yes cout << "Yes" << endl

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int N = 1010;  //
const int M = 10010; //
const int inf = 0x3f3f3f3f;
const ll lnf = 1e18;

ll f[N][M];
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

} a[N], bb[N];

void solve()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        if (i)
            cin >> bb[i].t >> bb[i].b >> bb[i].h;
        else
        {
            bb[0].t = 0;
            bb[0].b = 0;
            bb[0].h = 0;
        }
        a[i].t = 0;
        a[i].b = 0;
        a[i].h = 0;
    }
    sort(bb + 1, bb + n + 1);

    int nn = 0; //
    for (int i = 1; i <= n; ++i)
    {
        cout << a[i].t << " " << a[i].b << " " << a[i].h << "\n";

        if (bb[i].b == bb[i - 1].b)
        {
            a[nn].t += bb[i].t;
            a[nn].b = bb[i].b;
            a[nn].h += bb[i].h;
        }
        else
        {
            nn++;
            a[nn].t += bb[i].t;
            a[nn].b = bb[i].b;
            a[nn].h += bb[i].h;
        }
    }
    return;

    // n = nn;
    // cout << n << "\n";
    // for (int i = n; i >= 1; i--)
    // {
    //     cout << a[i].t << " " << a[i].b << " " << a[i].h << "\n";
    // for (int j = m; j >= a[i].t; j--)
    //     f[i][j] = max(f[i + 1][j], f[i + 1][j - a[i].t] + a[i].h);
    // for(int j=1;j<=m;j++){
    // cout << f[i][j] << ' ';
    // }
    // cout << endl;
    // }
    // ll sum = 0, happy = 0;
    // ll ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     // ans = max(ans, happy + f[i][sum + a[i].b - a[i - 1].b - 1]);
    //     sum += a[i].b - a[i - 1].b;
    //     sum -= a[i].t;
    //     if (sum < 0)
    //     {
    //         break;
    //     }
    //     happy += a[i].h;
    //     // cout << ans << ' ' << happy + f[i+1][sum] << ' ' << sum << endl;
    //     ans = max(ans, happy + f[i + 1][sum]);
    // }
    // cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}