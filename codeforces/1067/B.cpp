#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =3e5+1000;
const ll mod = 1e9+7;//998244353;
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

int f[maxn];
bool mark[maxn];
set <int> adj[maxn],q,qq;
int n , k;

int main(){
    //migmig
    cin >> n >> k;
    for (int i = 0 ; i < n-1 ; i ++){
        int u , v;
        cin >> u >> v;
        adj[v].insert(u);
        adj[u].insert(v);
    }
    for (int i = 1; i <= n ; i ++){
        if(adj[i].size() == 1){
            q.insert(i);
        }
    }
    while(n > 1){
        for (int v : q){
            int u = *adj[v].begin();
            qq.insert(u);
            adj[v].erase(u);
            adj[u].erase(v);
            f[u]++;
            n--;
        }
        for (int v : qq){
            if(f[v]<3){
                dokme("NO");
            }
            f[v]=-1e9;
        }
        swap(q , qq);
        qq.clear();
        k--;
    }
    cout<<((k == 0 && n==1)?"Yes":"No");
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
