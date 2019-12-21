#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int ,int > pii;
const ll maxn =5e5+10;
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
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}
struct edge{
	int x,y,w,srt;
};
edge edg[maxn];
int n , m  , t = 0  , df[maxn] , crnt , low[maxn] , ans[maxn] , w[maxn];
int par[maxn] , pre[maxn]  , di[maxn] , np[maxn] , rg[maxn] , out[maxn] , cs = 1;
vector < int > comp[maxn];
set <int> st;
bool mark[maxn];
int sz[maxn];
int mrk[maxn];
vector < vector <int> > vc[maxn];
vector <int> vec[maxn] , num[maxn];
bool f  = 0;
void dfs2( int v , int pr){
    mrk[v] = 1;
    bool seenpar = 0;
    for (auto u : vec[v]){
        if(!mrk[u]){
            dfs2(u , v);
        }
        else if (mrk[u] == 1){
            if(u != pr or  (u ==pr and seenpar)){
                f = 1;
            }
            else{
                seenpar  = 1;
            }
        }
    }
    mrk[v] = 2;
}
bool cmp(edge i , edge j){
    return(i.w < j.w);
}
bool cmp3(edge i , edge j){
    return(i.srt < j.srt);
}
bool cmp2(int i , int j){
    return(edg[i].w < edg[j].w);
}
int getpar(int v){
    if(par[v] == v){
        return(v);
    }
    par[v] = getpar(par[v]);
    return(par[v]);
}
void merge2(int x , int y){
    x = getpar(x) , y = getpar(y);
    if(x == y){
        return;
    }
    if(sz[x] > sz[y]){
        par[y] = x;
        sz[x]+=sz[y];
    }
    else{
        par[x] = y;
        sz[y]+=x;
    }
}
int main(){
    migmig
    memset(pre , 0 , sizeof pre );
    memset(ans , 0 , sizeof ans );
    memset(di , 0 , sizeof di );
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++){
        par[i] = i;
    }
    for (int i =1 ; i <= m ; i ++){
        cin >> edg[i].x >> edg[i].y >> edg[i].w;
        edg[i].srt = i;
    }
    sort(edg+1, edg+1 + m , cmp);
    int q;
    cin >> q;
    for (int i = 0 ; i <= n ; i ++){
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0 ; i <= m ; i ++){
        np[i] = i;
    }
    ms(rg , 0);
    ms(mark , 0);
    ms(di , 0);
    ms(out , 0);
    sort(edg + 1 , edg + m + 1 , cmp3);
    int cnt = 0;
    int wtf = q;
    while (q -- ){
        cnt ++;
        int k ;
        cin >> k;
        for (int i = 1;  i <= k;  i ++){
            int inp;
            cin >> inp;
            if(rg[edg[inp].w]!=cnt){
                rg[edg[inp].w] = cnt;
                vc[edg[inp].w].push_back( vector < int>()  );
                num[edg[inp].w].pb(cnt);
            }
            vc[edg[inp].w].back().pb(inp);
        }
        out[cnt] = 1;
    }
    sort(np  + 1 , np + m + 1 , cmp2);
    for(int i = 1; i <= m; i++){
		if(edg[np[i]].w != edg[np[i - 1]].w){
			int ppo = edg[np[i]].w;
			int s = num[ppo].size();
			for(int j = 0; j < s; j ++ ){
                vector <int> rk;
                rk.clear();
				for(auto ed : vc[ppo][j]){
					int u = getpar(edg[ed].x), v = getpar(edg[ed].y);
					rk.pb(u);
                    rk.pb(v);
					vec[u].pb(v);
					vec[v].pb(u);
				}
				f = 0;
				for(auto v : rk){
					if(!mrk[v]){
						dfs2(v, 0);
                    }
                }
				for(auto v : rk){
					mrk[v] = 0;
					vec[v].clear();
				}
				if(f){
                    out[num[ppo][j]] = 0;
                }
			}
		}
		merge2(edg[np[i]].x, edg[np[i]].y);
	}
    q = wtf;
    for (int i = 1 ; i <= q ; i ++){
        if(out[i]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
