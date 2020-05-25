#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int par[maxn];
int cct[6000][6000];
struct edge{
	ll u , v ,w, ind;
};
vector < edge > e , one,zk;
int n , m , k;
int pr[maxn];
bool mark[maxn];
edge edg[maxn];
int ans[maxn];
int getpar(int v){
	return((v == par[v])?v:par[v]=getpar(par[v]));
}
void init(){
	for(int i = 0 ; i < maxn ; i ++)
		par[i] = i ;
}
bool cmp (edge i , edge j){
	return(i.w < j.w);
}

void dfs(int v , int par = 0 , int ind = 0){
	if(edg[ind].w >= edg[pr[par]].w)
		pr[v]=ind;
	else
		pr[v] = pr[par];
	for(int u = 1 ; u <= n; u ++)
		if(cct[v][u] and u!=par)
			dfs(u , v , cct[v][u]);
}

void input(){
	cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; i ++){
		edge ed;
		cin >> ed.u >> ed.v >> ed.w;
		ed.ind = i;
		if(ed.u == 1)one.pb(ed);
		else if (ed.v == 1)swap(ed.u , ed.v) , one.pb(ed);
		else e.pb(ed);
		edg[i] = ed;
	}
}

int main(){
    migmig
    init();
    input();
	sort(one.begin() , one.end() , cmp);
	sort(e.begin() , e.end() , cmp);
    for(auto i : e){
		int u = i.u , v = i.v;
		if(getpar(u) == getpar(v))continue;
		par[getpar(u)] = getpar(v);
		cct[u][v] = cct[v][u] = i.ind;
		mark[i.ind]=1;
	}
	int cnt = 0;
	for(auto i : one){
		int u=i.u , v = i.v;
		u = getpar(u) , v = getpar(v);
		if(u == v)continue;
		par[v]=u;	
		dfs(i.v);
		cnt++;
		mark[i.ind]=1;
	}
    int comp = 0;
    for(int i = 1 ; i <= n ; i ++)
		if(i == getpar(i))
			comp++;
    if(comp > 1 or one.size() < k or cnt > k)dokme(-1);
    cnt = k-cnt;
    while(cnt --){
		for(auto i : one)
			if(!mark[i.ind]){
				edge e;
				e.u =i.ind;
				e.v =  pr[i.v] ;
				e.w =  i.w - edg[pr[i.v]].w;
				e.ind = i.v;
				zk.pb(e);}
		sort(zk.begin() , zk.end() , cmp);
		mark[zk[0].u] = 1 ,mark[zk[0].v] = 0;
		//cout << zk[0].w << ' ';
		//return(0);
		cct[edg[zk[0].v].u][edg[zk[0].v].v] = cct[edg[zk[0].v].v][edg[zk[0].v].u] = 0;
		dfs(zk[0].ind);
		zk.clear();
	}
	cnt=0;
    for(int i = 1 ; i <= m ; i ++)
		if(mark[i])
			ans[cnt++] = i;//
	cout << cnt << endl;
	for(int i = 0 ; i < cnt ; i ++)
		cout << ans[i] << ' ';
    return(0);
}