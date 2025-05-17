#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, k, x, y, h;
    cin >> n >> k >> x >> y >> h;
    x--;
    y--;

    vector<vector<bool>> is_general(n, vector<bool>(n, false));
    vector<vector<bool>> is_controlled(n, vector<bool>(n, false));

    for (int i = 0; i < k; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        is_general[a][b] = true;
        if (a > 0)
            is_controlled[a - 1][b] = true;
        if (a < n - 1)
            is_controlled[a + 1][b] = true;
        if (b > 0)
            is_controlled[a][b - 1] = true;
        if (b < n - 1)
            is_controlled[a][b + 1] = true;
    }

    vector<vector<int>> dist(n, vector<int>(n, INF));
    deque<pair<int, int>> dq;
    dist[x][y] = 0;
    dq.push_back({x, y});

    int dirs[] = {-1, 0, 1, 0, -1};

    while (!dq.empty())
    {
        int i = dq.front().first;
        int j = dq.front().second;
        dq.pop_front();

        for (int d = 0; d < 4; ++d)
        {
            int ni = i + dirs[d];
            int nj = j + dirs[d + 1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && !is_general[ni][nj])
            {
                int nc = dist[i][j] + (is_controlled[ni][nj] ? 1 : 0);
                if (nc < dist[ni][nj])
                {
                    dist[ni][nj] = nc;
                    if (nc == dist[i][j])
                    {
                        dq.push_front({ni, nj});
                    }
                    else
                    {
                        dq.push_back({ni, nj});
                    }
                }
            }
        }
    }

    int count = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == x && j == y)
                continue;
            if (is_general[i][j])
                continue;
            if (dist[i][j] <= h - 1)
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
