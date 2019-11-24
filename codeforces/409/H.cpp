#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int ,int > pii;

const ll maxn =2e5+10;
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

int par[maxn];
vector <int> comp[maxn];
int a , b;

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

int main(){
    migmig
    cin >> a >> b;
    int cnt = 0;
    for (int i = 0 ; i < a ; i ++){
        comp[i].pb(i);
        par[i] = i;
    }
    for (int i = 0 ; i < b ; i ++ , cnt ++){
        comp[cnt].pb(cnt);
        par[cnt] = cnt;
    }
    for (int i = 0 ; i < a ;  i ++){
        merge(0 , i);
    }
    for (int i = 0 , j = a ; i < b ; i ++ , j++){
        merge(a , j);
    }
    a-- , b--;
    merge(a , b);
    cout << comp[par[a]].size();



    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
