/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define u first
#define w second

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , L , W;
ll ans[maxn];
vector < pii > adj[maxn];

bool hide[maxn];
int sz[maxn];

void plant(int v , int par = 0){
	sz[v] = 1;
	for(auto [u , w] : adj[v])
		if(!hide[u] and u != par)	
			plant(u , v) , sz[v] += sz[u];
}

int cen(int v , int n , int par = 0 , bool found = 0){
	while(!found){
		found = 1;
		for(auto [u , w] : adj[v])
			if(u != par and !hide[u] and sz[u] * 2 > n){
				par = v , v = u , found = 0;
				break;
			}
	}
	return(v);
}

int h[maxn] , w[maxn];

vector < int > vec;

void add(int v , int par = 0 , int W = 0 , int h = 0){
	vec.pb(v);
	::h[v] = h , w[v] = W;
	for(auto [u , w] : adj[v])
		if(!hide[u] and u!=par)
			add(u , v , W + w , h + 1);
}

bool cmp(int a , int b){
	return(w[a] < w[b]);
}

bool cmp2(int a , int b){
	return(h[a] < h[b]);
}

vector < pii > vc;

struct oset{
    int maxn;
    vector < int > fen;
    oset(int n):
        maxn(n+100),
        fen(maxn){}
        
    void add(int x , int pos){
        for( ; pos < maxn ; pos += pos & -pos)
            fen[pos] += x;
    }
    int get(int pos){
        int sum = 0 ;
        for( ; pos  ; pos -= pos & -pos)
            sum += fen[pos];
        return(sum);
    }
    
    void insert(int x , int cnt = 1){
        add(cnt , x);
    }
    void erase(int x , int cnt = 1){
        add(-cnt , x);
    }
    int order_of_key(int key){
        return(get(key));
    }
};

oset st(maxn);

int pos[maxn];

void calc(int v , int t){
	int n = vec.size();
	vec.pb(0);
	w[0] = -1e9-10;
	h[0] = -1e9-10;
	sort(vec.begin() , vec.end() , cmp);
	for(int i = 1 ; i <= n ; i ++){
		int l = 0, r = i;
		while(r - l > 1){
			 int mid = (l + r)/2;
			 if(w[vec[mid]] <= W - w[vec[i]]) l = mid;
			 else r = mid;
		}
		if(L - h[vec[i]] >= 0)vc.pb({l , L - h[vec[i]]});
		pos[vec[i]] = i;
	}
	sort(vc.begin() , vc.end());
	int cur = 0;
	for(auto [r , x] : vc){
		while(cur < r)cur++ , st.insert(h[vec[cur]]+5);
		ans[v]+= t * st.order_of_key(x+5);
	}cur = 0;
	for(auto [r , x] : vc)
		while(cur < r)cur++ , st.erase(h[vec[cur]] +5);
	vc.clear();
}

void calc(int v){
	add(v);
	calc(v , 1);
	for(auto [u , w] : adj[v])
		if(!hide[u]) 
			vec.clear() , add(u , v , w , 1) , calc(v , -1); 
	vec.clear();
}

void solve(int v){
	plant(v);
	v = cen(v , sz[v]);
	hide[v] = 1;
	calc(v);
	for(auto [u , w] : adj[v])if(!hide[u])
		solve(u);
}

int32_t main(){
    migmig;
	cin >> n >> L >> W;
	for(int i = 2 ; i <= n ; i ++){
		int p , w;
		cin >> p >> w;
		adj[p].pb({i , w});
		adj[i].pb({p , w});
	}
	solve(1);
	ll res = 0;
	for(int i = 1 ; i <= n ; i ++)
		res += ans[i];
	cout << res;
    return(0);
}
