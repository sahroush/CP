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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
int a[maxn];
int cnt[maxn];
int sz[maxn];
int ans[maxn];
bool mark[maxn];

unordered_map < int , int > mp;
int cur = 0;

int comp(int x){
	if(mp.count(x))return(mp[x]);
	return((mp[x] = cur++));
}

const int sq = 3500;

struct query{
	int l , r , t , id;
	friend bool operator < (query a , query b){
		if(a.l / sq == b.l / sq){
			if(a.r / sq == b.r / sq)
				return(a.t < b.t);
			return(a.r < b.r);
		}
		return(a.l < b.l);
	}
};

vector < query > change , calc;

void add(int x){
	if(cnt[x])sz[cnt[x]]--;
	cnt[x]++;
	sz[cnt[x]]++;
}

void rm(int x){
	if(cnt[x])sz[cnt[x]]--;
	cnt[x]--;
	assert(cnt[x] >= 0);
	if(cnt[x])sz[cnt[x]]++;
}

vector < pii > und;

void modify(int x){
	und.pb({change[x].l , a[change[x].l]});
	if(mark[change[x].l])rm(a[change[x].l]);
	a[change[x].l] = change[x].r;
	if(mark[change[x].l])add(a[change[x].l]);
}

void undo(){
	pii u = und.back();
	und.pop_back();
	if(mark[u.first])rm(a[u.first]);
	a[u.first] = u.second;
	if(mark[u.first])add(a[u.first]);
}

int32_t main(){
    migmig;
    mp.max_load_factor(0.13);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , a[i] = comp(a[i]);
	change.pb({1 , 1 , 1 , 1});
	for(int i = 0 ; i < q ; i ++){
		query qu;
		cin >> qu.t >> qu.l >> qu.r;qu.id = i;
		if(qu.t == 1)
			qu.t = change.size()-1 , calc.pb(qu);
		else
			qu.r = comp(qu.r) , change.pb(qu);
	}
	sort(calc.begin() , calc.end());
	int cur = 0;
	int l = 1 , r = 1 , t = 0;
	add(a[1]);
	mark[1] = 1;
	while(cur < (int)calc.size()){
		while(l > calc[cur].l){
			l--;
			if(!mark[l])add(a[l]);
			mark[l] = 1;
		}
		while(r < calc[cur].r){	
			r++;
			if(!mark[r])add(a[r]);
			mark[r] = 1;
		}
		while(l < calc[cur].l){
			if(mark[l])rm(a[l]);
			mark[l] = 0;
			l++;
		}
		while(r > calc[cur].r){
			if(mark[r])rm(a[r]);
			mark[r] = 0;
			r--;
		}
		while(t < calc[cur].t){
			t++;
			modify(t);
		}
		while(t > calc[cur].t){
			undo();
			t--;
		}
		for(int i = 1 ; ; i ++){
			if(sz[i] == 0){
				ans[calc[cur].id] = i;
				break;
			}
		}
		cur++;
	}
	sort(calc.begin() , calc.end() , [](query a , query b){return(a.id < b.id);});
	for(int i = 0 ; i < (int)calc.size() ; i ++)
		cout << ans[calc[i].id] << endl;
    return(0);
}
