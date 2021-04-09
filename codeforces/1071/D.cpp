#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6+1;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
map < ll , int > mp;
vector < int > chan[maxn];
ll vect[maxn];
ll num[5000];
int san[maxn];
bool bad[maxn];
int sz = 0;
map < int , int > cunt;
vector < int > fuck[810];

void build(int tot , int lim , ll chan){
	if(!mp.count(chan))mp[chan] = ++sz;
	for(ll i = 1 ; i <= lim && i <= tot ; i ++){
		chan <<= 1LL;
		chan <<= i;
		chan |= (1LL << i) - 1;
		build(tot - i , i , chan);
		chan>>=(i+1);
	}
}

vector < int > adj[5000];
int dist[810][5000];

void make(){
	for(int i = 1 ; i <= sz ; i ++){
		ll val = num[i];
		if(mp.count(((val << 2LL) | 1)))
			adj[i].pb(mp[((val << 2LL) | 1)]);
		ll u = val >> 1LL;
		u >>= (u & -u);
		u <<= 1 , u |= 1;
		adj[i].pb(mp[u]);
		adj[i].pb(mp[val >> 1LL]);
		for(ll j = 0 ; j < 46 ; j ++){
			ll u = (val>>j)<<(j+1) | (1LL << j) | (val & ((1LL << j)-1));
			if(abs(__builtin_popcount(u) - __builtin_popcount(val)) <= 1 and u != val)
				if(mp.count(u))adj[i].pb(mp[u]);
			u = (val >> (j+1))<<(j) | (val & ((1LL << j)-1));
			if(abs(__builtin_popcount(u) - __builtin_popcount(val)) <= 1 and u != val and (val & (1LL << j)))
				if(mp.count(u))adj[i].pb(mp[u]);
		}
	}
}

int f(int v){
	ll x = num[v];
	int cnt = 0;
	int res = 1;
	for(ll i = 1 ; i <= x ; i<<=1LL){
		if(i & x)
			cnt++;
		else
			res *= (cnt + 1) , cnt = 0;
	}
	res *= (cnt + 1);
	return res;
}

void spfa(int x){
	queue < int > q;
	ms(dist[x] , -1);
	for(auto v : fuck[x])dist[x][v] = 0 , q.push(v);
	while(q.size()){
		int v = q.front();
		q.pop();
		for(auto u : adj[v])if(dist[x][u] == -1)
			dist[x][u] = dist[x][v] + 1, q.push(u);
	}
}

int32_t main(){
	migmig;
	for(int i = 0 ; i < maxn ; i ++)san[i] = i;
	for(int i = 2 ; i <= 1000 ; i ++)if(!bad[i]){
		for(int j = i ; j < maxn ; j += i){
			int cnt = 0;
			bad[j] = 1;
			while(san[j] % i == 0)san[j] /= i , cnt++;
			chan[j].pb(cnt);
		}
	}
	for(int i = 1 ; i < maxn ; i ++){
		if(san[i] ^ 1)chan[i].pb(1);
		sort(chan[i].begin() , chan[i].end());
		reverse(chan[i].begin() , chan[i].end());
		for(int x : chan[i])vect[i] <<= 1LL , vect[i]<<=x , vect[i] |= (1LL << x) - 1;
		if(!mp.count(vect[i]))mp[vect[i]] = ++sz;
	}
	build(22 , 22 , 0);
	for(auto [f , s] : mp)num[s] = f;
	make();
	sz = 0;
	for(auto [F , s] : mp){if(!cunt.count(f(s)))cunt[f(s)] = ++sz; fuck[cunt[f(s)]].pb(s);}
	//I have no idea why this even compiles
	for(int i = 1 ; i <= 803 ; i ++)spfa(i);
	cin >> q;
	while(q--){
		int a , b;
		cin >> a >> b;
		int ans = 20;
		int kire = mp[vect[a]] , khar = mp[vect[b]];
		for(int i = 1 ; i <= 803 ; i ++)ans = min(ans , dist[i][kire] + dist[i][khar]);
		cout << ans << endl;
	}
	return(0);
}
