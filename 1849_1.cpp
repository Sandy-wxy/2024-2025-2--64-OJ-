#include <bits/stdc++.h>
#define endl "\n"
#define x first
#define y second
#define no cout << "No" << endl
#define yes cout << "Yes" << endl

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int N = 360;
const int inf = 0x3f3f3f3f;
const ll lnf = 1e18;

int v[N];
int T, n, m;
int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
int cnt[5];
int f[51][51][51][51];
int ans;

void dfs(int u, int a, int b, int c, int d, int h)
{
    if (h <= f[a][b][c][d])
        return;
    f[a][b][c][d] = h;
    ans = max(ans, h);
    if (a + 1 <= cnt[1])
        dfs(u + 1, a + 1, b, c, d, h + v[u + 1]);
    if (b + 1 <= cnt[2])
        dfs(u + 2, a, b + 1, c, d, h + v[u + 2]);
    if (c + 1 <= cnt[3])
        dfs(u + 3, a, b, c + 1, d, h + v[u + 3]);
    if (d + 1 <= cnt[4])
        dfs(u + 4, a, b, c, d + 1, h + v[u + 4]);
}

void solve()
{
    cin >> n >> m;
    memset(f, -1, sizeof f);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    dfs(1, 0, 0, 0, 0, v[1]);
    // cout << f[3][1][1][0] << endl;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}