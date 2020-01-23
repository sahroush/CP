#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5;
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

int n , m;
vector < int > vec[maxn];
int par[maxn];
vector < int > adj[maxn] , radj[maxn];
string s[maxn];
int cnt[maxn];
int ans[maxn];
int deg[maxn];

int getpar(int v){
    if(v == par[v]){
        return(v);
    }
    return(par[v] = getpar(par[v]));
}

void merge(int u, int v){
    u = getpar(u);
    v = getpar(v);
    if(u == v){
        return;
    }
    par[v] = u;
}

int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i <= n + m ; i ++){
        par[i]=i;
    }
    for (int i = 0 ; i< n ; i ++){
        cin >> s[i];
    }
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ;  j < m ; j ++){
            if(s[i][j] == '='){
                merge(i , j + n);
            }
        }
    }
    for (int i = 0 ; i < n ; i ++){
        for (int j  = 0 ; j < m ; j ++){
            int u = getpar(i);
            int v = getpar(j + n);
            if(s[i][j] == '<'){
                adj[u].pb(v);
                radj[v].pb(u);
            }
            if(s[i][j] == '>'){
                radj[u].pb(v);
                adj[v].pb(u);
            }
        }
    }
    int cnt = 0;
    vector < int > sik;
    for (int i = 0 ; i < n + m ; i ++){
        deg[i] = radj[i].size();
        if(radj[i].size() == 0){
            sik.pb(i);
        }
    }
    int num = 1;
    while(cnt!=n + m){
        vector <int> del;
        del.clear();
        if(sik.size() == 0){
            dokme("No");
        }
        for (int v : sik){
            cnt++;
            ans[v] = num;
            for (int u : adj[v]){
                deg[u] --;
                if(deg[u] == 0){
                    del.pb(u);
                }
            }
        }
        num++;
        sik = move(del);
    }
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < m ; j ++){
            int u = ans[getpar(i)];
            int v = ans[getpar(j + n)];
            if(s[i][j] == '=' and u!=v){
                dokme("No");
            }
            if(s[i][j] == '>' and u<=v){
                dokme("No");
            }
            if(s[i][j] == '<' and u>=v){
                dokme("No");
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0 ; i < n ; i ++){
        cout << ans[getpar(i)] << ' ';
    }
    cout << endl;
    for (int i = 0 ; i < m ; i ++){
        cout << ans[getpar(i + n)] << ' ';
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
