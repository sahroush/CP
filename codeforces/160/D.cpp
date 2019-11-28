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

struct edge{
	int x,y,w,srt;
};

edge edg[maxn];

int n , m  , t = 0  , df[maxn] , crnt , low[maxn] , ans[maxn] , w[maxn];
int par[maxn] , pre[maxn]  , di[maxn] , np[maxn] , rg[maxn] , out[maxn] , cs = 1;
vector < int > comp[maxn];
set <int> st;
bool mark[maxn];

bool cmp(edge i , edge j){
    return(i.w < j.w);
}

int getpar(int v){
    if(par[v] == v){
        return(v);
    }
    par[v] = getpar(par[v]);
    return(par[v]);
}

/*
bool merge(int x , int y){
    if(getpar(x) == getpar(y)){
        return(0);
    }
    x = getpar(x) , y = getpar(y);
    if(comp[y].size() > comp[x].size()){
        swap(x , y);
    }
    //ot = out , r = rg , cp = cs , nt = np , hd = di
    while(!comp[y].empty()){
        int u = comp[y][comp[y].size() - 1];
        comp[y].pop_back();
        comp[x].pb(u);
        par[u] = x;
    }
    return(1);
}
*/
void merge(int x , int y , int z , int v){
    out [ ++cs ] = y;
	w[cs] = z , rg [cs] = v;
	np[cs] = di[x];
	di[x] = cs;
}

void dfs(int v){
	mark[v]=1;
	df[v] = low[v] = ++t;
	for(int i=di[v];i!=0 and w[i] == crnt; i =np[i]){
    	if ( i!=pre[v] ){
    		int u=out[i];
    		if ( mark[u]==0 ){
    			pre[u]=i;
                if(pre[u]%2){
                    pre[u]--;
                }
                else {
                     pre[u]++;
                }
    			dfs(u);
    			if ( low[u] < low[v] ){
                    low[v]=low[u];
                }
    			if (low[u] > df[v] ){
                    ans[rg[i]]=2;
                }
    		}
    		if ( mark[u]==1 and low[u] < low[v] ){
                low[v] = low[u];
            }
    	}
    }
	if (low[v]==df[v]){
        t=df[v]-1;
    }
}

void solve(){
	int s=1,tpp,o,p;
	while ( s<=m ){
        //cout << (s);
        //cout << m;
		tpp=s;
        crnt=edg[s].w;
		while ( edg[tpp].w==edg[s].w  ){
            o=getpar(edg[tpp].x);
			p=getpar(edg[tpp].y);
			if ( o!=p ){
				ans[edg[tpp].srt]=1;
                merge(o,p,edg[tpp].w,edg[tpp].srt);
				merge(p,o,edg[tpp].w,edg[tpp].srt);
				mark[o]=mark[p]=0;
			}
            else{
                ans[edg[tpp].srt]=0;
            }
			tpp++;
		}
		for(int i=s;i<tpp;i++){
			if ( getpar(edg[i].x)!=getpar(edg[i].y) ){
				o=getpar(edg[i].x);
				p=getpar(edg[i].y);
				t=0;
				if (!mark[o]) dfs(o);
				t=0;
				if (!mark[p]) dfs(p);
			}
        }
		for(int i = s ; i< tpp; i++){
			par[getpar(edg[i].x)]=getpar(edg[i].y);
        }
        //cout << tpp;
		s=tpp;
	}
}

int main(){
    //migmig
    memset(pre , 0 , sizeof pre );
    memset(ans , 0 , sizeof ans );
    memset(di , 0 , sizeof di );
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++){
        par[i] = i;
    }
    for (int i =1 ; i <= m ; i ++){
        cin >> edg[i].x >> edg[i].y >> edg[i].w;

        //edg.pb(make_pair(w[i] , make_pair(x , y)));
        //srt[i] = i;
        edg[i].srt = i;
    }
    sort(edg+1, edg+1 + m , cmp);
    solve();
    for (int i = 1 ; i <= m ; i ++){
        if(ans[i] == 0){
            puts("none");
        }
        else if(ans[i] == 1){
            puts("at least one");
        }
        else{
            puts("any");
        }
    }
    //fuck!
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
