//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

#define mid ((l+r)>>1)
#define lc (v<<1)
#define rc (lc|1)

const int sq = 50;

int n , q;
string s[maxn];
int lcp[maxn];
set < int > st;

int calc(int x){
	if(s[x].size() > sq)st.insert(x);
	if(x == n)return(0);
	for(int i = 0 ; i < (int)min(s[x].size() , s[x + 1].size()) ; i ++)
		if(s[x][i] != s[x + 1][i])
			return(i);
	return(min(s[x].size() , s[x + 1].size()));
}

struct maxseg{
	vector < int > seg;
	maxseg():
		seg(maxn*4){}
	void build(int v = 1 , int l = 1 , int r = maxn){
		if(r - l == 1){
			seg[v] = s[l].size();
			return;
		}
		build(lc , l , mid);
		build(rc , mid , r);
		seg[v] = max(seg[lc] , seg[rc]);
	}
	void update(int pos , int v = 1 , int l = 1 , int r = maxn){
		if(pos == 0)return;
		if(r - l == 1){
			seg[v] = s[l].size();
			return;
		}
		if(pos < mid)
			update(pos , lc , l , mid);
		else
			update(pos , rc , mid , r);
		seg[v] = max(seg[lc] , seg[rc]);
	}
	int query(int L , int R , int v = 1 , int l = 1 , int r = maxn){
		if(r <= L or R <= l)
			return(0);
		if(L <= l and r <= R)
			return(seg[v]);
		return(max(query(L , R , lc , l , mid) , query(L , R , rc , mid , r)));
	}
};

struct wut{
	int pref , ans , suff , len;
	wut(int a = 0, int b = 0 , int c = 0):
		pref(a) , ans(b) , suff(c) , len(1){}
	friend wut operator + (wut a , wut b){
		wut c(0 , 0 , 0);
		c.len = a.len + b.len;
		c.pref = a.pref;
		if(a.pref == a.len)	
			c.pref+=b.pref;
		c.suff = b.suff;
		if(b.suff == b.len)
			c.suff+=a.suff;
		c.ans = max({a.ans , b.ans , a.suff + b.pref});
		return(c);
	}
};

struct wutseg{
	vector < wut > seg;
	wutseg ():
		seg(maxn*4){}
	int x;
	void build(int v = 1 , int l = 1 , int r = maxn){
		if(r - l == 1){
			seg[v].suff = seg[v].pref = seg[v].ans = (lcp[l] >= x);
			return;
		}
		build(lc , l , mid);
		build(rc , mid , r);
		seg[v] = seg[lc] + seg[rc];
	}
	void update(int pos , int v = 1 , int l = 1 , int r = maxn){
		if(pos == 0)return;
		if(r - l == 1){
			seg[v].suff = seg[v].pref = seg[v].ans = (lcp[l] >= x);
			return;
		}
		if(pos < mid)
			update(pos , lc , l , mid);
		else
			update(pos , rc , mid , r);
		seg[v] = seg[lc] + seg[rc];
	}
	wut query(int L , int R , int v , int l , int r){
		if(r <= L or R <= l)
			return(wut(0 , 0 , 0));
		if(L <= l and r <= R)
			return(seg[v]);
		return(query(L , R , lc , l , mid) + query(L , R , rc , mid , r));
	}
	int query(int L , int R){
		return(query(L , R , 1 , 1 , maxn).ans);
	}
};

maxseg mxseg;
wutseg seg[sq];

int a[2000];
int par[2000] , sz[2000];
pii srt[2000];

int getpar(int v){
	return((v == par[v]) ? v : par[v] = getpar(par[v]));
}

void merge(int u , int v){
	u = getpar(u) , v = getpar(v);
	par[u] = v;
	sz[v] += sz[u];
}

ll solve(int l , int r){
	if(st.size() == 0)return(0);
	int cur = 0;
	auto it = st.lower_bound(l);
	for( ; it!=st.end() and *it <= r ; it ++)
		a[++cur] = *it;
	for(int i = 1 ; i <= cur ; i ++)
		par[i] = i , sz[i] = 1;
	for(int i = 1 ; i <= cur ; i ++)
		srt[i] = pii(-lcp[a[i]] , i);
	sort(srt + 1 , srt + cur + 1);
	ll ans = 0;
	for(int i = 1 ; i <= cur ; i ++){
		auto [y , x] = srt[i];
		if(x == cur)continue;
		if(a[x]+1 == a[x + 1])
			merge(x , x + 1) , ans = max(ans ,sz[getpar(x)]*1LL*-y);
	}
	return(ans);
}

int32_t main(){
    migmig;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i];
	for(int i = 1 ; i <= n ; i ++)
		lcp[i] = calc(i);
	mxseg.build();
	for(int i = 1 ; i <= sq ; i ++)seg[i-1].x = i , seg[i-1].build();
	while(q -- ){
		int t;
		cin >> t;
		if(t == 1){
			int l , r;
			cin >> l >> r;
			ll ans = mxseg.query(l , r+1);
			if(l == r){cout << ans << endl;continue;}
			for(int i = 1 ; i <= sq ; i ++){
				int res = seg[i-1].query(l , r);
				if(res)
					ans = max(ans , i*1LL*(res + 1));
			}
			ans = max(ans , solve(l , r));
			cout << ans << endl;
		}
		else{
			int x;string y;
			cin >> x >> y;
			s[x] = y;
			if(st.count(x))st.erase(x);
			lcp[x] = calc(x);
			lcp[x-1]=calc(x-1);
			mxseg.update(x);
			mxseg.update(x-1);
			for(int i = 1 ; i <= sq ; i ++)seg[i-1].update(x) , seg[i-1].update(x-1);
		}
	}
    return(0);
}
