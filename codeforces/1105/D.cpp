#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e3+100;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m , p;
int f[10];
int dist[maxn][maxn];
string s[maxn];
vector < pii > prop[10];
queue < pii > q;
int ans[10];

bool bfs(){
    for (int i = 1 ; i <= p ; i ++){
        for (auto v : prop[i]){
            q.push(v);
            dist[v.first][v.second] = 0;
        }
        ans[i]+=prop[i].size();
        prop[i].clear();
        pii dir []= {{0 , 1} , {1 , 0} , {-1,0} , {0 ,-1 }};
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            for (auto j : dir){
                pii u = {j.first + v.first , j.second + v.second};
                if(u.first >= 0 and u.first < n and u.second >= 0 and u.second < m){
                    if(s[u.first][u.second] == '.'){
                        if(dist[v.first][v.second] < f[i]){
                            q.push(u);
                            dist[u.first][u.second] = dist[v.first][v.second] + 1;
                            prop[i].pb(u);
                            s[u.first][u.second] = char('0' + i);
                        }
                    }
                }
            }
        }
    }
    bool an = 0;
    for (int i = 1; i <= p ; i ++){
        an|=(!prop[i].empty());
    }
    return(an);
}

int main(){
    migmig
    assert(dominance);
    cin >> n >> m >> p;
    for (int  i = 1 ; i <= p ; i ++){
        cin >> f[i];
    }
    for (int i = 0 ; i < n ; i ++){
        cin >> s[i];
        for (int j = 0 ; j < m ; j ++){
            if(s[i][j]!='.' and s[i][j]!='#'){
                prop[s[i][j] - '0'].pb(pii( i , j));
            }
        }
    }
    while(bfs()){
        //          :|
    }
    for (int i = 1 ; i <= p ; i ++ ){
        cout << ans[i] << ' ';
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
