/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 5e5 + 10;
const int sigma = 26;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
string s[maxn];
int f[maxn] , nxt[sigma][maxn] , trie = 0 , pos[maxn] , ext[maxn];
bool endpoint[maxn];
vector < int > adj[maxn];

int add(string s){
	int cur = 0;
	for(char c : s){
		if(!nxt[c - 'a'][cur])nxt[c - 'a'][cur] = ++ trie;
		cur = nxt[c - 'a'][cur];
	}
	return(cur);
}

struct que{
	int q[maxn] , l = 0 , r = 0;
	void push(int x){
		q[r++] = x;
	}
	int pop(){
		return(q[l++]);
	}
	int size(){
		return(r - l);
	}
};

void build(){
	que q;
	for(int i = 0 ; i < sigma ; i ++)if(nxt[i][0])q.push(nxt[i][0]);
	while(q.size()){
		int v = q.pop();
		ext[v] = (endpoint[f[v]] ? f[v] : ext[f[v]]);
		adj[f[v]].pb(v);
		for(int i = 0 ; i < sigma ; i ++)
			if(nxt[i][v]) f[nxt[i][v]] = nxt[i][f[v]] , q.push(nxt[i][v]);
			else nxt[i][v] = nxt[i][f[v]];
	}
}

int fen[maxn] , st[maxn] , ft[maxn] , ti = 0 , ans[maxn] , h[maxn];

void add(int pos , int x){
	for( ; pos < maxn ; pos += pos & -pos)
		fen[pos] += x;
}

int get(int pos){
	int ans = 0;
	for( ; pos ; pos -= pos & -pos)
		ans += fen[pos];
	return(ans);
}

int get(int l , int r){
	return(get(r) - get(l - 1));
}

void dfs(int v = 0){
	st[v] = ++ti;
	for(int i : adj[v])h[i] = h[v] + 1 , dfs(i);
	ft[v] = ti;
}

vector < pii > qu[maxn];

void eat(string s){
	int cur = 0;
	for(char c : s){
		cur = nxt[c - 'a'][cur];
		int x = cur;
		while(x)
			add(st[x] , 1) , x = ext[x];
	}
}

int32_t main(){
	migmig;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i] , pos[i] = add(s[i]);
	build();
	dfs();
	for(int i = 1 ; i <= q ; i ++){
		int l , r , k;
		cin >> l >> r >> k;
		qu[r].pb({pos[k] , i});
		qu[l - 1].pb({pos[k] , -i});
	}
	for(int i = 1 ; i <= n ; i ++){
		eat(s[i]);
		for(auto [v , q] : qu[i])
			ans[abs(q)] += (abs(q) / q) * get(st[v] , ft[v]);
	}
	for(int i = 1 ; i <= q ; i ++)
		cout << ans[i] << endl;
	return(0);
}
