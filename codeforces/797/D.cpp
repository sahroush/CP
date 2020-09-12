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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int l[maxn] , r[maxn];
int val[maxn];
int root[maxn];
int ans;
map < int , int > mp;

void dfs(int v, int mn = 0 , int mx = 1e9 ){
	bool bad = (val[v] > mx or val[v] < mn);
	if(!bad) ans -= mp[val[v]],
	mp[val[v]] = 0;
	if(l[v] > 0){
		dfs(l[v] , mn , min(mx , val[v]));
	}
	if(r[v] > 0){
		dfs(r[v] , max(mn , val[v]) , mx);
	}
}

int32_t main(){
    migmig
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> val[i] >> l[i] >> r[i];
		if(l[i] > 0)root[l[i]] = 1;
		if(r[i] > 0)root[r[i]] = 1;
		mp[val[i]] ++;
	}
	ans = n;
	int r = min_element(root + 1 , root + n + 1) - root;
	dfs(r);
	dokme(ans);
    return(0);
}