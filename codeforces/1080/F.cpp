//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
//#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const int sq = 400;

/*
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
}block[sq];
*/

#define sz(x) int(x.size())

int n , m , q;
vector < pii > seg[maxn];
struct tr{
	int a , b , c;
	friend bool operator  < (tr a , tr b){
		return make_pair(pii(a.a , a.b) , a.c) < make_pair(pii(b.a , b.b) , b.c);
	}
};

vector < tr > block[sq];
deque < int > dq[sq];
multiset < int > st;

bool chk(int i , int l , int r){
	int pos = lower_bound(seg[i].begin() , seg[i].end() , pii(l , 0)) - seg[i].begin();
	if(pos == sz(seg[i]))return 0;
	return seg[i][pos].second <= r;
}

void build(int i){
	sort(block[i].begin() , block[i].end());
	st.clear();
	for(int i = 0 ; i < sq ; i ++)dq[i].clear();
	for(int l = 0 , r = 0 ; l < sz(block[i]) ; l ++){
		while(r < sz(block[i]) and sz(st) < sq){
			tr x = block[i][r++];
			dq[x.c%sq].pb(x.b);
			if(sz(dq[x.c%sq]) == 1)st.insert(x.b);
		}
		if(sz(st) < sq)
			seg[n + i].pb(pii(block[i][l].a , 1e9+10));
		else
			seg[n + i].pb(pii(block[i][l].a , *st.rbegin()));
		int v = block[i][l].c % sq;
		st.erase(st.find(dq[v].front()));
		dq[v].pop_front();
		if(!dq[v].empty())st.insert(dq[v].front());
	}
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> q >> m;
	for(int i = 1 ; i <= m ; i ++){
		int l , r , x;
		cin >> l >> r >> x;
		x--;
		seg[x].pb({l , r});		
	}
	for(int i = 0 ; i < n ; i ++){
		sort(seg[i].begin() , seg[i].end());
		for(int j = sz(seg[i]) - 2 ; j >= 0 ; j --)
			seg[i][j].second = min(seg[i][j].second , seg[i][j+1].second);
		for(auto [l , r] : seg[i])
			block[i/sq].pb({l , r , i});
	}
	for(int i = 0 ; i < sq ; i ++)
		build(i);
	while(q --){
		int l , r , a , b;
		cin >> a >> b >> l >> r;
		a--;
		bool ok = 1;
		while(ok and a < b and a%sq)ok &= chk(a , l , r) , a++;
		while(ok and a < b and b%sq)b -- , ok &= chk(b , l , r);
		while(ok and a < b) ok &= chk(n + a/sq , l , r) , a+= sq;
		cout << ((ok) ? "yes" : "no") << endl;
	}
	return(0);
}
