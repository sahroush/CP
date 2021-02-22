#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const int sigma = 27;

int n;
string s;
int pos[maxn];
int val[maxn];
int sz = 0;
bool endpoint[maxn];
int nxt[sigma][maxn] , f[maxn] , ext[maxn];

int add(string &s){
	int cur = 0;
	for(char c : s){
		if(!nxt[c - 'a'][cur])nxt[c - 'a'][cur] = ++sz;
		cur = nxt[c - 'a'][cur];
	}
	endpoint[cur] = 1;
	return(cur);
}

struct que{
	int l = 0 , r = 0;
	int q[maxn];
	void push(int x){
		q[r++] = x;
	}
	int front(){
		return(q[l]);
	}
	void pop(){
		l++;
	}
	int size(){
		return(r - l);
	}
}q;

vector < int > adj[maxn];

int st[maxn] , ft[maxn] , ti = 0;

void dfs(int v){
	st[v] = ++ti;
	for(auto u : adj[v])	
		dfs(u);
	ft[v] = ti;
}

void build(){
	for(int i = 0 ; i < sigma ; i ++)if(nxt[i][0])q.push(nxt[i][0]);
	while(q.size()){
		int v = q.front();
		q.pop();
		if(endpoint[f[v]])ext[v] = f[v];
		else ext[v] = ext[f[v]];
		for(int i = 0 ; i < sigma ; i ++)
			if(!nxt[i][v])nxt[i][v] = nxt[i][f[v]];
			else f[nxt[i][v]] =  nxt[i][f[v]] , q.push(nxt[i][v]);
	}
	for(int i = 1 ; i <= sz ; i ++)	
		adj[ext[i]].pb(i);
	dfs(0);
}

int fen[maxn];

void add(int pos , int x){
	for(; pos < maxn ; pos += pos & -pos)
		fen[pos] += x;
}

void add(int l , int r , int x){
	add(l , x);
	add(r + 1 , -x);
}

int get(int pos){
	int res = 0;
	for(; pos ; pos -= pos & -pos)	
		res += fen[pos];
	return(res);
}

int32_t main(){
	migmig;
	int q;
	cin >> q >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> s;
		pos[i] = add(s);
	}
	build();
	for(int i = 1 ; i <= n ; i ++)
		add(st[pos[i]] , ft[pos[i]] , 1);
	while(q--){
		char t;
		cin >> t;
		if(t == '+'){
			int i;
			cin >> i;
			if(!endpoint[pos[i]])add(st[pos[i]] , ft[pos[i]] , 1);
			endpoint[pos[i]] = 1;
		}
		else if(t == '-'){
			int i;
			cin >> i;
			if(endpoint[pos[i]])add(st[pos[i]] , ft[pos[i]] , -1);
			endpoint[pos[i]] = 0;
		}
		else{
			string s;
			cin >> s;
			int ans = 0;
			int cur = 0;
			for(char c : s){
				cur = nxt[c - 'a'][cur];
				ans += get(st[cur]);
			}
			cout << ans << endl;
		}
	}
	return(0);
}
