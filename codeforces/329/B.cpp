#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn = 1100;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int r , c;
string s[maxn];
queue <pii> q;
bool mark[maxn][maxn];
int dist[maxn][maxn] ;
pii  par[maxn][maxn] ;
pii pos , start;

pii dfs(pii v){
    int x = v.first , y = v.second;
    if (par[x][y] == pos){
        return(v);
    }
    dfs(par[x][y]);
}


int main (){
    migmig
    cin >> r >> c;
    for (int i = 0; i < r ; i ++){
        cin >> s[i];
        for (int j = 0 ; j < c ; j++){
            if (s[i][j] == 'E'){
                pos.first = i;
                pos.second = j;
            }
            if (s[i][j] == 'S'){
                start.first = i;
                start.second = j;
            }
        }
    }
    memset(dist , -1 , sizeof(dist));
    dist[pos.first][pos.second] = 0;
    mark[pos.first][pos.second] = 1;
    par[pos.first][pos.second] = make_pair(-1, -1);
    q.push(pos);
    while(!q.empty()){
        pii v = q.front();
        q.pop();
        int x = v.first , y = v.second;
        if (x + 1 < r and !mark[x+1][y] and s[x+1][y]!='T'){
            par[x+1][y] = make_pair(x , y);
            dist[x+1][y] = dist[x][y] + 1;
            q.push(make_pair(x+1 , y));
            mark[x+1][y] = 1;
        }
        if (x - 1 >= 0 and !mark[x-1][y] and s[x-1][y]!='T'){
            par[x-1][y] = make_pair(x , y);
            dist[x-1][y] = dist[x][y] + 1;
            q.push(make_pair(x - 1 , y));
            mark[x-1][y] = 1;
        }
        if (y + 1 < c and !mark[x][y+1] and s[x][y+1]!='T'){
            par[x][y+1] = make_pair(x , y);
            dist[x][y+1] = dist[x][y] + 1;
            q.push(make_pair(x , y + 1));
            mark[x][y+1] = 1;
        }
        if (y - 1 >= 0 and !mark[x][y-1] and s[x][y-1]!='T'){
            par[x][y-1] = make_pair(x , y);
            dist[x][y-1] = dist[x][y] + 1;
            q.push(make_pair(x , y - 1));
            mark[x][y-1] = 1;
        }
    }
    int stdst = dist[start.first][start.second];
    /*
    pii pth = dfs(start);
    pos = pth;
    memset(dist , -1 , sizeof(dist));
    memset(mark, 0 , sizeof(mark));
    memset(par , 0 , sizeof(par));
    dist[pos.first][pos.second] = 0;
    mark[pos.first][pos.second] = 1;
    par[pos.first][pos.second] = make_pair(-1, -1);
    */
    ll cnt = 0;
    /*
    q.push(pos);
    while(!q.empty()){
        pii v = q.front();
        q.pop();
        int x = v.first , y = v.second;
        if (x + 1 < r and !mark[x+1][y] and s[x+1][y]!='T'){
            par[x+1][y] = make_pair(x , y);
            dist[x+1][y] = dist[x][y] + 1;
            q.push(make_pair(x+1 , y));
            mark[x+1][y] = 1;
        }
        if (x - 1 >= 0 and !mark[x-1][y] and s[x-1][y]!='T'){
            dist[x-1][y] = dist[x][y] + 1;
            q.push(make_pair(x - 1 , y));
            mark[x-1][y] = 1;
        }
        if (y + 1 < c and !mark[x][y+1] and s[x][y+1]!='T'){
            dist[x][y+1] = dist[x][y] + 1;
            q.push(make_pair(x , y + 1));
            mark[x][y+1] = 1;
        }
        if (y - 1 >= 0 and !mark[x][y-1] and s[x][y-1]!='T'){
            dist[x][y-1] = dist[x][y] + 1;
            q.push(make_pair(x , y - 1));
            mark[x][y-1] = 1;
        }
    }
    dokme(dist[0][1]);
    */
    for (int i = 0 ; i < r ;  i++){
        for (int j = 0 ; j < c ; j++){
            if (s[i][j]!='S' and s[i][j]!='T' and s[i][j]!='E' and dist[i][j] <= stdst and dist[i][j]!=-1){
                int num = s[i][j] - '0';
                cnt+=num;
            }
        }
    }
    cout << cnt;

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you wiint come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
