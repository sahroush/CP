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

struct trio{
	int f , s , t;
};

int n, m;
vector < int > adj[maxn] , back[maxn] , child[maxn];
map < pii , bool > mp;
int par[maxn];
bool mark[maxn];
vector < trio > ans;

void dfs(int v){
	mark[v] = 1;
	for (auto u : adj[v]){
		if(!mark[u]){
			child[v].pb(u);
			par[u] = v;
			dfs(u);
		}
		else if (u!=par[v]){
			back[v].pb(u);
		}
	}
	int f = 0  , s = 0, cnt = 0 , moond = -1;
	
	
	//******************children**********************
	//find a back_edge;
	int be = -1;
	for (int i = 0 ; i < back[v].size() ;  i++){
		if(!mp[pii(v , back[v][i])]){
			be = back[v][i];
			break;
		}
	}
	//continue ... ;
	
	
	cnt = 0 , moond = -1 , s = 0 , f = 0;
	while(child[v].size()){
		if(cnt == 0 and !mp[pii(child[v].back() , v)]){
			f = child[v].back();
			cnt++;
		}
		else if(cnt == 1 and !mp[pii(child[v].back() , v)]){
			s = child[v].back();
			cnt=2;
		}
		if(cnt == 2){
			cnt = 0;
			trio boz;
			mp[pii(v , f)] = mp[pii(f , v)] = 1;
			mp[pii(v , s)] = mp[pii(s , v)] = 1;
			boz.f = f , boz.s= v , boz.t = s;
			ans.pb(boz);
		}
		if(!mp[pii(child[v].back() , v)]){
			moond = child[v].back();
		}
		child[v].pop_back();
	}
	
	if(moond!=-1 and !mp[pii(be , v)] and !mp[pii(moond , v)] and be!=-1){
		trio boz;
		boz.f = moond , boz.s = v , boz.t = be;
		mp[pii(v , moond)] = mp[pii(moond , v)] = 1;
		mp[pii(v , be)] = mp[pii(be , v)] = 1;
		ans.pb(boz);
	}
	
	if(moond!=-1 and !mp[pii(par[v] , v)] and par[v]!=-1 and !mp[pii(moond , v)]){
		trio boz;
		boz.f = moond , boz.s = v , boz.t = par[v];
		mp[pii(v , moond)] = mp[pii(moond , v)] = 1;
		mp[pii(v , par[v])] = mp[pii(par[v] , v)] = 1;
		ans.pb(boz);
	}
	
	
	
	
	
	//************************************************
	
	
	
	
	//*************************back edge**************
	cnt = 0 , moond = -1 , f = 0 , s = 0;
	while(back[v].size()){
		if(cnt == 0 and !mp[pii(back[v].back() , v)]){
			f = back[v].back();
			cnt++;
		}
		else if(cnt == 1 and !mp[pii(back[v].back() , v)]){
			s = back[v].back();
			cnt=2;
		}
		if(cnt == 2){
			cnt = 0;
			trio boz;
			mp[pii(v , f)] = mp[pii(f , v)] = 1;
			mp[pii(v , s)] = mp[pii(s , v)] = 1;
			boz.f = f , boz.s= v , boz.t = s;
			ans.pb(boz);
		}
		if(!mp[pii(back[v].back() , v)]){
			moond = back[v].back();
		}
		back[v].pop_back();
	}
	if(moond!=-1 and !mp[pii(par[v] , v)] and par[v]!=-1 and !mp[pii(v , moond)]){
		trio boz;
		boz.f = moond , boz.s = v , boz.t = par[v];
		mp[pii(v , moond)] = mp[pii(moond , v)] = 1;
		mp[pii(v , par[v])] = mp[pii(par[v] , v)] = 1;
		ans.pb(boz);
	}
	//**************************************************
	
	
	
}
 
int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++){
    	int u , v;
    	cin >> u >> v;
    	adj[v].pb(u);
    	adj[u].pb(v);
    	mp[pii(u , v)] = mp[pii(v , u)] = 0;
	}
	
	for (int i = 1 ; i <= n ; i ++){
		if(!mark[i]){
			par[i] = -1;
			dfs(i);
		}
	}
    cout << ans.size() << endl;
    for (int i = 0 ; i < ans.size() ; i ++){
    	trio out;
    	out  = ans[i];
    	cout << out.f << ' ' << out.s << ' ' << out.t << endl;
	}
    
    
    return(0);
}





