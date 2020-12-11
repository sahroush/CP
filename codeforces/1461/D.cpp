/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
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

int q;
int n;
int a[maxn];
int w[maxn];
set < int > st;
vector < pii > vec;
int prt[maxn];

void dfs(int l , int r){
	st.insert(prt[r] - prt[l - 1]);
	if(r == l)
		return;
	int mid = (vec[r].first + vec[l].first)/2;
	int Mid = upper_bound(vec.begin() , vec.end() , pii(mid+1 , 0)) - vec.begin();
	dfs(l , Mid - 1);
	dfs(Mid , r);
}

void solve(){
	int q;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	st.clear();
	vec.clear();
	vec.pb({0 , 0});
	for(int i = 1 ; i <= n ; i ++){
		if(vec.back().first != a[i])
			vec.pb({a[i] , a[i]});
		else
			vec.back().second += a[i];
	}
	for(int i = 0 ; i < (int)vec.size() ; i ++){
		if(!i)prt[i] = vec[i].second;
		prt[i] = vec[i].second + prt[i - 1];
	}
	dfs(1 , vec.size()-1);
	while(q -- ){
		int s;
		cin >> s;
		cout << ((st.count(s)) ? "Yes" : "No") << endl;
	}
}

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		solve();
	}
	return(0);
}
