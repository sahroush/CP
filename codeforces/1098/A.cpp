#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5+5;
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

int n;
int p[maxn];
ll s[maxn];
bool f = 1;
vector < int > adj[maxn];
bool mark[maxn];
ll val[maxn];

void dfs(int v , int par){
    if(!f){
        return;
    }
    if(s[v] == -1){
        ll mn = 1e13;
        for (auto u : adj[v]){
            if(u!=par){
                mn = min(mn , s[u]);
            }
        }
        if(mn > s[par] and mn!=1e13){
            s[v] = mn;
            val[v] = mn - s[par];
        }
        else{
            s[v] = s[par];
            val[v] = 0;
        }
    }
    else{
        if(s[par] > s[v]){
            f = 0;
            return;
        }
        else{
            val[v] = s[v] - s[par];
        }
    }
    for (auto u : adj[v]){
        if(u!=par){
            dfs(u , v);
        }
    }
}

int main(){
    migmig
    cin >> n;
    p[1] = 1;
    for (int i = 2 ; i <= n ; i ++){
        cin >> p[i];
        adj[p[i]].pb(i);
    }
    for (int i = 1 ; i<= n ; i ++){
        cin >> s[i];
    }
    dfs(1 , 0);
    if(!f){
        dokme(-1);
    }
    ll ans = 0;
    for (int i = 1; i <= n ; i ++){
        ans+=val[i];
    }
    dokme(ans);
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
