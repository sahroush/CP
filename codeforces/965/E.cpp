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

const ll maxn = 1e5 + 100;
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
int ch[sigma+5][maxn];
int val[maxn];

int cur = 0;

void add(string s){
	int pos = 0;
	int n = s.size();
	for(int i = 0 ; i < n ; i ++){
		if(!ch[s[i] - 'a'][pos])ch[s[i] - 'a'][pos] = ++cur;
		pos = ch[s[i] - 'a'][pos];
	}
	val[pos]++;
}

int ans[maxn] ,  mx[maxn];
vector < int > bag[maxn];

#define sz(x) (int(x.size()))

void merge(int v , int u){
	if(sz(bag[v]) < sz(bag[u]))
		swap(bag[v] , bag[u]) , swap(ans[v] , ans[u]);
	for(auto x : bag[u])
		bag[v].pb(x) , ans[v] += x;
	bag[u].clear();
	sort(bag[v].begin() , bag[v].end());
}

int solve(int v , int h = 0){
	if(val[v]){
		bag[v].pb(h);
		ans[v] = h;
	}
	for(int i = 0 , u = ch[0][v] ; i < sigma ; i ++ , u = ch[i][v])
		if(u)
			solve(u , h + 1) , merge(v , u);
	if(!val[v] && v){
		if(bag[v].size())
			ans[v] -= bag[v].back() , bag[v].pop_back();
		bag[v].pb(h);
		ans[v] += h;
	}
	return(ans[v]);
}


int32_t main(){
    migmig;
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> s , add(s);
	cout << solve(0);
    return(0);
}
