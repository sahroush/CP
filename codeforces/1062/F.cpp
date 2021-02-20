//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 5e5 + 1000;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;

vector < int > in[maxn] , out[maxn];

int d[maxn];

queue < int > q;

int par[maxn];

vector < int > top;

void topo(){
	for(int i = 1 ; i <= n ; i ++)
		d[i] = in[i].size();
	for(int i = 1 ; i <= n ; i ++)
		if(d[i] == 0)
			q.push(i);
	while(!q.empty()){
		int v = q.front();
		top.pb(v);
		q.pop();
		for(auto u : out[v]){
			d[u] --;
			if(d[u] == 0){
				par[u] = v;
				q.push(u);
			}
		}
	}
}

int ord[maxn];

int a[maxn];
int b[maxn];

int L[maxn] , R[maxn];

bool cmp(int i , int j){
	return(ord[i] < ord[j]);
}

vector < int > vec;

int l[maxn] , r[maxn];

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int  i = 0 ; i < m ; i ++){
		int u , v;
		cin >> u >> v;
		out[u].pb(v);
		in[v].pb(u);
	}
	top.pb(858585);
	topo();
	for(int i = 1 ; i <= n ; i ++)
		ord[top[i]] = i;
	for(int i = 1; i <= n; i ++){
		sort(in[i].begin() , in[i].end() , cmp);
		sort(out[i].begin() , out[i].end() , cmp);
	}
	for(int i = 1 ; i <= n ; i ++){
		R[i] = n + 1;
		if(in[i].size())L[i]=ord[in[i].back()];
		if(out[i].size())
			R[i] = ord[out[i][0]];
		int l = L[i] , r = R[i];
		a[l+1]++, a[ord[i]]-- , a[ord[i]+1]++ , a[r]--;
		b[l+1]+=i, b[ord[i]]-=i , b[ord[i]+1]+=i , b[r]-=i;
	}
	for(int i = 1 ; i <= n ; i ++)
		a[i] = a[i] + a[i - 1],
		b[i] = b[i] + b[i - 1];
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		ans += (a[i] == 0);
	for(int i = 1 ; i <= n ; i ++)	
		if(a[i] == 1)
			vec.pb(i);
	for(int i = 1 ; i <= n ; i ++){
		l[i] = n+1;
		for(auto v : in[i]){
			if(top[R[v]] == i){
				if(out[v].size() > 1){
					r[i] = max(r[i] , ord[out[v][1]]);
				}else r[i] = n+1;
			}
		}
		for(auto v : out[i]){
			if(top[L[v]] == i){
				if(in[v].size() > 1){
					l[i] = min(l[i] , ord[in[v][int(in[v].size()) - 2]]);
				}else l[i] = 0;
			}
		}
	}
    for(auto V : vec){
		int v = top[V];
		if(ord[b[ord[v]]] > ord[v])
			ans += (l[b[ord[v]]] >= ord[v]);
		else
			ans += (r[b[ord[v]]] <= ord[v]);
	}
	cout << ans;
    return(0);
}
