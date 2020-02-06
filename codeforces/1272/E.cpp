#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
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

int n , a[maxn];
vector < int > adj[maxn];
queue <int> q;
ll dist[maxn];
bool mark[maxn];
int ans[maxn];

int main(){
    migmig
    cin >> n ;
    ms(dist , 63);
    ms(ans , 63);
    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        if(i - a[i] > 0 ){
            adj[i - a[i]].pb(i );
        }
        if(i + a[i] <= n){
            adj[i + a[i]].pb(i );
        }
        if(a[i]%2 == 1){
            q.push(i);
            mark[i] = 1;
            dist[i] = 0;
        }
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (auto u : adj[v]){
            if(!mark[u]){
                mark[u] = 1;
                dist[u] = dist[v] + 1;
                ans[u] = dist[u];
                q.push(u);
            }
        }
    }
    ms(dist , 63);
    ms(mark , 0);
    for (int i = 1 ; i <= n ; i ++){
        if(a[i]%2 == 0){
            q.push(i);
            mark[i] = 1;
            dist[i] = 0;
        }
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (auto u : adj[v]){
            if(!mark[u]){
                mark[u] = 1;
                dist[u] = dist[v] + 1;
                ans[u] = dist[u];
                q.push(u);
            }
        }
    }
    for (int i = 1 ; i <= n ; i ++){
        if(ans[i] == ans[0]){
            cout << -1 << ' ';
        }
        else{
            cout << ans[i] << ' ';
        }
    }
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
