#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int n , m;
vector < int > adj[maxn];
int s;
queue < pii > q;
bool mark[maxn][2];
bool draw = 0 ;
int mrk[maxn];
int par[maxn][2];
stack < int > stk;

void solve(int v , bool f = 1){
    if(v == -1){
        return;
    }
    stk.push(v);
    solve(par[v][f] , !f);
}

void dfs(int v){
    mrk[v] =1;
    for(auto u : adj[v]){
        if(mrk[u]==1){
            draw = 1;
            return;
        }
        if(mrk[u] == 2){
            continue;
        }
        dfs(u);
    }
    mrk[v] = 2;
}

int main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++){
        int k;
        cin >> k;
        for(int j = 0 ; j < k ; j ++){
            int inp;
            cin >> inp;
            adj[i].pb(inp);
        }
    }
    cin >> s;
    q.push(pii(s , 0));
    par[s][0] = -1;
    mark[s][0] = 1;
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        if(v.second == 1 and adj[v.first].size() == 0){
            cout << "Win" << endl;
            solve(v.first);
            while(!stk.empty()){
                cout << stk.top() << ' ';
                stk.pop();
            }
            return(0);
        }
        for(auto u : adj[v.first]){
            bool f = !v.second;
            if(mark[u][f]){
                continue;
            }
            q.push(pii(u , f));
            mark[u][f] = 1;
            par[u][f] = v.first;
        }
    }
    dfs(s);
    if(draw){
        dokme("Draw");
    }
    cout << "Lose";


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
