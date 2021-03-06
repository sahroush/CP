#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =1e5+5;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

vector < int > adj[maxn] , radj[maxn] , ans[maxn];
int n , m , res;
int num[maxn];
bool mark[maxn];

void dfs(int v , int c){
    ans[v].pb(c);
    if(!mark[v]){
        mark[v] = 1;
        for (auto u : adj[v]){
            dfs(u , c+1);
        }
        for (auto u : radj[v]){
            dfs(u , c - 1);
        }
    }
}

int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        radj[v].pb(u);
    }
    for (int i = 1 ; i <= n ; i ++){
        if(!mark[i]){
            dfs(i , 0);
        }
    }
    for (int i = 1 ; i<= n ; i ++){
        for (int j = 1 ; j < ans[i].size() ; j ++){
            res = __gcd(res ,abs(ans[i][j] - ans[i][j - 1]));
        }
    }
    if(res){
        dokme(res)
    }
    cout << n;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
