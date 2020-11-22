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

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int dp[maxn];
int lst[maxn];
int n , m;

struct ed{
	int u , v , w;
	friend bool operator < (ed a , ed b){
		return(a.w < b.w);
	}
};

vector < ed > e;

int pd[maxn];

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++){
		int u , v , w;
		cin >> u >> v >> w;
		e.pb({u , v , w});
	}
	sort(e.begin() , e.end());
 	for(int i = 0 ; i < m ;){
		int j = i;
		while(e[j+1].w == e[i].w)j++;
		for(int k = i ; k <= j ; k ++)pd[e[k].v] = max(pd[e[k].v] , dp[e[k].u] + 1);
		for(int k = i ; k <= j ; k ++)dp[e[k].v] = pd[e[k].v];
		i = j+1;
	}
	cout << *max_element(dp , dp + maxn);
    return(0);
}