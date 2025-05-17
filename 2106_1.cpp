#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, -1, 0, 0}; // 控制方向（包括自身）
int dy[] = {0, 0, 0, 1, -1};

int n, k, start_x, start_y, h;
int e[1001][1001];           // 地图：1=可走，0=不可走
bool visited[1001][1001][6]; // 是否访问过 (x, y, 剩余血量)
bool occupied[1001][1001];   // 是否已经被占领

struct Node
{
    int x, y, hp;
};

void solve()
{
    cin >> n >> k >> start_x >> start_y >> h;

    // 初始化为全可走
    memset(e, 1, sizeof(e));

    // 标记将及其控制区
    for (int i = 0; i < k; ++i)
    {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < 5; ++j)
        {
            int nx = a + dx[j];
            int ny = b + dy[j];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
            {
                e[nx][ny] = 0; // 将控制区标记不可走
            }
        }
    }

    queue<Node> q;
    int result = 0;

    // 起点处理
    int init_hp = h;
    if (e[start_x][start_y] == 0)
        init_hp--;
    if (init_hp <= 0)
    {
        cout << 1 << '\n'; // 起点也算领地
        return;
    }

    q.push({start_x, start_y, init_hp});
    visited[start_x][start_y][init_hp] = true;
    occupied[start_x][start_y] = true;
    result = 1;

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        for (int d = 1; d <= 4; ++d)
        {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 1 || nx > n || ny < 1 || ny > n)
                continue;

            int nhp = cur.hp;
            if (e[nx][ny] == 0)
                nhp--;

            if (nhp <= 0)
                continue;
            if (visited[nx][ny][nhp])
                continue;

            visited[nx][ny][nhp] = true;

            if (!occupied[nx][ny])
            {
                occupied[nx][ny] = true;
                ++result;
            }

            q.push({nx, ny, nhp});
        }
    }

    cout << result << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
