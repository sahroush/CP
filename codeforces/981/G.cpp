//*
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
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
			auto L = st[x].lower_bound({ l , 0}) , R = st[x].upper_bound({r , n});
			if(L != st[x].begin()){
				L--;
				if((*L).second < l) L++;
			}
			vector < pii > q;
			for(auto it = L ; it != R ; it = st[x].erase(it))q.pb(*it);
			if(q.empty()){
				update(l , r + 1 , 1);
				st[x].insert({ l  , r });
				continue;
			}
			int cur = l;
			int LL = l , RR = r;
			for(auto [a , b] : q){
				if(a > cur)
					update(cur , a , 1) , cur = a;
				LL = min(LL , a) , RR = max(RR , b);
				update(cur , min(r , b)+1 , 0);
				cur = min(r , b) + 1;
				st[x].erase({a , b});
			}
			if(q.back().second < r)update(cur , r+1 , 1);
			st[x].insert({LL , RR});
		}
		else{
			cout << query(l , ++r) << endl;
		}
	}
    return(0);
}
