#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < int > adj[maxn];
int val[maxn];
ll ans = 0 , cur;
ll odd[maxn] , even[maxn];

void dfs(int v , int par = 0){
    odd[v] = even[v] = 0;
    if(val[v]&cur){
        odd[v] += 1;
    }
    else{
        even[v]+=1;
    }
    for (auto u : adj[v]){
        if(u!=par){
            dfs(u , v);
        }
        else{
            continue;
        }
        ans+= (cur) * (even[v]*odd[u] + odd[v]*even[u]);
        if(val[v]&(cur)){
            odd[v]+=even[u];
            even[v]+=odd[u];
        }
        else{
            odd[v]+=odd[u];
            even[v]+=even[u];
        }
    }

}

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> val[i];
        ans+=val[i];
    }
    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    for(int i = 0 ; i < 21 ; i ++){
        cur = (1 << i);
        dfs(1);
    }
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
