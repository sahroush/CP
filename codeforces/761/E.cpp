#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int n;
vector <int> adj[maxn];
pll pos[maxn];

void dfs(int v = 1 , ll t = 2147483648, int p = 0 , int dir = 0){
    int cnt = 0;
    if(v == 1){
        for (auto u : adj[v]){
            if(cnt==0){
                pos[u] = pos[v];
                    pos[u].first+=t;
                    dfs(u , t/2 , v , 0);
                }
                if(cnt == 1){
                    pos[u] = pos[v];
                    pos[u].second+=t;
                    dfs(u , t/2 , v , 3);
                }
                if(cnt == 2){
                    pos[u] = pos[v];
                    pos[u].second-=t;
                    dfs(u , t/2 , v , 2);
                }
                if(cnt==3){
                    pos[u] = pos[v];
                    pos[u].first-=t;
                    dfs(u , t/2 , v , 1);
                }
                cnt++;
        }
        return;
    }
    for (auto u : adj[v]){
        if(u!=p){
            if(dir == 0){
                if(cnt==0){
                    pos[u] = pos[v];
                    pos[u].first+=t;
                    dfs(u , t/2 , v , 0);
                }
                if(cnt == 1){
                    pos[u] = pos[v];
                    pos[u].second+=t;
                    dfs(u , t/2 , v , 3);
                }
                if(cnt == 2){
                    pos[u] = pos[v];
                    pos[u].second-=t;
                    dfs(u , t/2 , v , 2);
                }
                cnt++;
            }
            if(dir == 1){
                if(cnt==0){
                    pos[u] = pos[v];
                    pos[u].first-=t;
                    dfs(u , t/2 , v , 1);
                }
                if(cnt == 1){
                    pos[u] = pos[v];
                    pos[u].second+=t;
                    dfs(u , t/2 , v , 3);
                }
                if(cnt == 2){
                    pos[u] = pos[v];
                    pos[u].second-=t;
                    dfs(u , t/2 , v , 2);
                }
                cnt++;
            }
            if(dir == 2){
                if(cnt==0){
                    pos[u] = pos[v];
                    pos[u].first+=t;
                    dfs(u , t/2 , v , 0);
                }
                if(cnt == 1){
                    pos[u] = pos[v];
                    pos[u].first-=t;
                    dfs(u , t/2 , v , 1);
                }
                if(cnt == 2){
                    pos[u] = pos[v];
                    pos[u].second-=t;
                    dfs(u , t/2 , v , 2);
                }
                cnt++;
            }
            if(dir == 3){
                if(cnt==0){
                    pos[u] = pos[v];
                    pos[u].first+=t;
                    dfs(u , t/2 , v , 0);
                }
                if(cnt == 1){
                    pos[u] = pos[v];
                    pos[u].second+=t;
                    dfs(u , t/2 , v , 3);
                }
                if(cnt == 2){
                    pos[u] = pos[v];
                    pos[u].first-=t;
                    dfs(u , t/2 , v , 1);
                }
                cnt++;
            }

        }
    }
}

int main(){
    migmig
    cin >> n;
    for (int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1 ; i <= n ; i ++){
        if(adj[i].size() > 4){
            dokme("NO");
        }
    }
    cout << "YES" << endl;
    pos[1] = {0 , 0};
    dfs();
    for (int i = 1 ; i <= n ; i ++){
        cout << pos[i].first << ' ' << pos[i].second << endl;
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
