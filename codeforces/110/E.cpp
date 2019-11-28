#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int ,int > pii;

const ll maxn =3e5+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n;
ll ans = 0;
int par[maxn];
vector < int > comp[maxn];

int getpar(int v){
    if(par[v] == v){
        return(v);
    }
    par[v] = getpar(par[v]);
    return(par[v]);
}
void merge(int x , int y){
    if(getpar(x) == getpar(y)){
        return;
    }
    x = getpar(x) , y = getpar(y);
    if(comp[y].size() > comp[x].size()){
        swap(x , y);
    }
    while(!comp[y].empty()){
        int u = comp[y][comp[y].size() - 1];
        comp[y].pop_back();
        comp[x].pb(u);
        par[u] = x;
    }
}

bool islucky(int num){
    while(num!=0){
        if(num%10!=4 and num%10!=7){
            return(0);
        }
        num/=10;
    }
    return(1);
}

int main(){
    migmig
    cin >> n;
    for (int i = 1  ; i <= n; i ++){
        par[i]=i;
        comp[i].pb(i);
    }
    for (int i = 0 ; i < n - 1 ; i ++){
        int x , y , w;
        cin >> x >> y >> w;
        bool f = islucky(w);
        if (!f){
            merge(x , y);
        }
    }
    for (int i = 1 ; i <= n; i ++){
        ans += (ll)(n - comp[par[i]].size()) * (ll)((n - comp[par[i]].size()) - 1);
    }
    cout << ans;

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
