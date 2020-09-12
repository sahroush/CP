/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m ;
vector < pii > adj[maxn];
vector < pair < pii , pii > > edge;
vector < int > ans;

int mark[maxn];

bool cycle(int v , int mid){
	mark[v] = 1;
	for(auto [u , w] : adj[v]){
		if(w < mid) continue;
		if(mark[u] == 0)
			if(cycle(u , mid))
				return(1);
		if(mark[u] == 1)
			return(1);
	}
	mark[v] = 2;
	return(0);
}

bool check(int mid){
	ms(mark , 0);
	for(int i = 1; i <= n ; i ++)
		if(!mark[i])
			if(cycle(i , mid))
				return(0);
	return(1);
}

queue < int > q;
int in[maxn] , out[maxn];
int order[maxn];

void solve(int x){
	for(int i = 1 ; i <= n ; i ++){
		for(auto [u , w] : adj[i]){
			if(w >= x){
				out[i]++;
				in[u]++;
			}
		}
	}
	int cur = 1;
	for(int i = 1 ; i <= n ; i ++){
		if(in[i] == 0)
			q.push(i);
	}
	while(!q.empty()){
		int v = q.front();
		order[v] = cur;
		cur ++;
		q.pop();
		for(auto [u , w] : adj[v])
			if(w >= x)
				{
					in[u]--;
					if(in[u] == 0)
						q.push(u);
				}
	}
	for(auto [a , b] : edge){
		auto [u , v] = a;
		auto [w , i] = b;
		if(order[u] > order[v]){
			ans.pb(i);
		}
	}
}


int32_t main(){
    migmig
	cin >> n >> m;
	for(int i = 1; i <= m ; i ++){
		int u , v;
		int w;
		cin >> u >> v >> w;
		adj[u].pb({v , w});
		edge.pb({{u , v} ,{w , i}});
	}
	int l = 0 , r = 1e9+1;
	while(r - l > 1){
		int mid = (l + r)/2;
		if(check(mid))
			r = mid;
		else 
			l = mid;
	}
	r--;
	cout << r << ' ';
	solve(r+1);
	cout << ans.size() << endl;
	for(int i : ans)
		cout << i << ' ';
    return(0);
}