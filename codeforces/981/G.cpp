//*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e5 + 100;
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
//ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
int lazy[maxn*4][2], pw[maxn];
int ans[maxn*4];
set < pii > st[maxn];

vector < pii > vec;

struct range{
	set < pii > st;
	void add(int l , int r , vector < pii > &vec = vec){
		vec.clear();
		auto L = st.lower_bound({l , 0});
		auto R = st.upper_bound({r , 1e9+3});
		if(L != st.begin()){
			L --;
			if((*L).second < l)L++;
		}
		vector < pii > v;
		for(auto it = L ; it != R ; it = st.erase(it))v.pb(*it);
		if(v.empty()){
			vec.pb({l , r});
			st.insert({l , r});
			return;
		}
		int cur = l;
		int LL = l , RR = r;
		for(auto ab : v){
			auto a = ab.first;
			auto b = ab.second;
			if(a > cur)
				vec.pb({cur , a-1}), cur = a;
			LL = min(LL , a) , RR = max(RR , b);
			cur = min(r , b) + 1;
			st.erase({a , b});
		}
		if(v.back().second < r)vec.pb({cur , r});
		st.insert({LL , RR});
	}
	void remove(int l , int r , vector < pii > &vec = vec){
		vec.clear();
		auto L = st.lower_bound({l , 0});
		auto R = st.upper_bound({r , 1e9+3});
		if(L != st.begin()){
			L --;
			if((*L).second < l)L++;
		}
		vector < pii > v;
		for(auto it = L ; it != R ; it = st.erase(it))v.pb(*it);
		if(v.empty()){
			return;
		}
		for(auto ab : v){
			auto a = ab.first;
			auto b = ab.second;
			st.erase({a , b});
			vec.pb({max(l , a), min(b , r)});
			if(a < l)
				st.insert({a , l-1});
			if(b > r)
				st.insert({r+1 , b});
		}
	}
};


void fufu(int v , int u){
	lazy[u][0] += lazy[v][0];
	lazy[u][1] = (lazy[u][1] *1LL* pw[lazy[v][0]])%mod;
	lazy[u][1] = (lazy[u][1] + lazy[v][1])%mod;
}	

void shift(int v , int l , int r){
	ans[v] = (ans[v] *1LL* pw[lazy[v][0]])%mod;
	ans[v] = (ans[v] + (lazy[v][1] * 1LL * (r - l))%mod)%mod;
	if(r - l > 1)
		fufu(v , 2*v),
		fufu(v , 2*v+1);
	lazy[v][0] = lazy[v][1] = 0;
}

void update(int L , int R ,int val, int v = 1 , int l = 1,  int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		lazy[v][val] = 1;
		shift(v , l , r);
		return;
	}
	int mid = (l + r)/2;
	update( L , R , val, 2*v , l , mid);
	update(L , R , val , 2*v + 1 , mid , r);
	ans[v] = (ans[2*v] + ans[2*v + 1])%mod;
}

ll query(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l, r);
	if(r <= L or R <= l)
		return(0);
	if(L <= l and r <= R)
		return(ans[v]);
	int mid = (l + r)/2;
	return((query(L , R , 2*v , l , mid) + query(L , R , 2*v + 1 , mid , r))%mod);
}	

range R[maxn];

int32_t main(){
    migmig;
    pw[0] = 1;
    for (int i = 1; i < maxn; i++) pw[i] = 1LL * pw[i - 1] * 2 % mod;
	cin >> n >> q;
	while(q -- ){
		int t , l , r , x;
		cin >> t >> l >> r;
		if(t == 1){
			cin >> x;
			R[x].add(l , r);
			for(auto [L , R] : vec){
				update(L , R + 1 , 1);
				if(l < L)
					update(l , L , 0);
				l = R + 1;
			}
			update(l , r+1 , 0);
		}
		else{
			cout << query(l , ++r) << endl;
		}
	}
    return(0);
}
