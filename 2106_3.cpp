#include<bits/stdc++.h>
#define endl "\n"
#define x first
#define y second
#define no cout << "No" << endl
#define yes cout << "Yes" << endl

using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int N = 1010;
const int inf = 0x3f3f3f3f;
const ll lnf = 1e18;

int T,n,m;
int dx[4] = {0,1,-1,0},dy[4] = {1,0,0,-1};
int st[N][N];
int g[N][N];
PII a[N*1000];

struct node{
    int x,y,hp;
};

void solve(){
    int n,x,y,k,h;
    cin >> n >> k >> x >> y >> h;
    queue<node> q;
    q.push({x,y,h});
    int ans = 0;
    g[x][y] = 1;
    for(int i=1;i<=k;i++){
        cin >> a[i].x >> a[i].y;
        for(int j=0;j<4;j++){
            st[a[i].x+dx[j]][a[i].y+dy[j]] = 1;
        }
    }
    for(int i=1;i<=k;i++){
        st[a[i].x][a[i].y] = 2;
    }
    while(q.size()){
        auto [x,y,hp] = q.front();
        q.pop();
        ans += 1;
        for(int i=0;i<4;i++){
            int a = dx[i] + x,b = dy[i] + y;
            if(st[a][b] == 2) continue;
            if(a >= 1 && a <= n && b >= 1 && b <= n && hp - st[a][b] > 0 && g[a][b] == 0){
                g[a][b] = 1;
                q.push({a,b,hp - st[a][b]});
            }
        }
        
    }
    cout << ans ;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    
    return 0;
}