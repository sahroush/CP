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
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k ;
vector < int > pos;
vector < int > iq;
int x[maxn] , r[maxn] , a[maxn];
ll ans = 0;

vector < int > group[maxn];

int comp(int x , vector < int > &v){
	return(lower_bound(v.begin() , v.end() , x) - v.begin() + 1);
}

bool cmp(int i , int j){
	return(r[i] > r[j]);
}

struct BIT{
	int fen[maxn];
	vector < int > vec;
	void add(int x , int pos){
		vec.pb(pos);
		for( pos+=5 ; pos < maxn ; pos += pos & -pos)
			fen[pos] += x;
	}
	int get(int pos){
		int ans = 0;
		for(pos+=5; pos ; pos -= pos & -pos)
			ans += fen[pos];
		return(ans);
	}
	int get(int l  ,int r){
		return(get(r) - get(l - 1));
	}
	void clear(){
		for(auto pos : vec)
			for(pos+=5 ; pos < maxn ; pos += pos & -pos)
				fen[pos] = 0;
		vec.clear();
	}
};

BIT fen , org;

void solve(int X){
	vector < int > cur;
	cur.clear();
	for(int i = X ; i <= X + k ; i ++)
		for(auto u : group[i])
			cur.pb(u);
	sort(cur.begin() , cur.end() , cmp);
	for(int i : cur){
		if(a[i] == iq[X-1]){
			ans += fen.get(comp(x[i] - r[i] , pos) , comp(x[i] + r[i] , pos));
			fen.add(1 , comp(x[i] , pos));
			org.add(1 , comp(x[i] , pos));
		}
		else{
			ans += org.get(comp(x[i] - r[i] , pos) , comp(x[i] + r[i] , pos));
			fen.add(1 , comp(x[i] , pos));
		}
	}
	fen.clear();
	org.clear();
}

int32_t main(){
    migmig;
	cin >> n >> k;
	for(int i = 1 ; i <= n;  i ++ ){
		cin >> x[i] >> r[i] >> a[i];
		pos.pb(x[i]);
		pos.pb(x[i] - r[i]);
		pos.pb(x[i] + r[i]);
		for(int j = 0 ; j <= k ; j ++)
			iq.pb(a[i] + j);
	}
	sort(pos.begin() , pos.end());
	sort(iq.begin() , iq.end());
	pos.resize(unique(pos.begin() , pos.end()) - pos.begin());
	iq.resize(unique(iq.begin() , iq.end()) - iq.begin());
	for(int i = 1 ; i <= n ; i ++)
		group[comp(a[i] , iq)].pb(i);
	for(int i = 1 ; i < maxn ; i ++){
		if(group[i].size())	
			solve(i);
	}
	cout << ans;
    return(0);
}