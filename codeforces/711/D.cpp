#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6+100;
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

ll t2[maxn] , n;
int  adj[maxn];
int mark[maxn];
ll ans = 1 , cycnt = 0;
ll cycle[maxn];

void fc(int v){
    cycle[cycnt]++;
    mark[v] = 3;
    if(mark[adj[v]] == 3){
        return;
    }
    fc(adj[v]);
}


void dfs(int v){
    mark[v]  =1;
    if(mark[adj[v]] == 0){
        dfs(adj[v]);
    }
    else if(mark[adj[v]] == 2){
        mark[v] = 2;
        return;
    }
    else{
        fc(v);
        cycnt++;
    }
    mark[v] = 2;
}


int main(){
    migmig
    ms(mark , 0);
    assert(dominance);
    t2[0] = 1;
    for (int i = 1 ; i <= 1000000 ; i ++){
        t2[i] = t2[i - 1]*2;
        t2[i]%=mod;
    }
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> adj[i];
    }
    for (int i = 1; i <= n ; i ++){
        if(!mark[i]){
            dfs(i);
        }
    }
    ll cnt = n;
    for (int i  = 0 ; i < cycnt+10 ; i ++){
        if(cycle[i] == 0){
            break;
        }
        cnt-=cycle[i];
        ans*=((t2[cycle[i]] - 2 + mod*100)%mod)%mod;
        ans%=mod;
    }
    ans = (ans * t2[cnt])%mod;
    ans+=mod*100;
    ans%=mod;
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
