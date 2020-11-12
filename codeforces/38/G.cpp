/*
#pragma GCC optimize("O2")
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

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn] , c[maxn];
const int sq = 600;

deque < int > q[sq];

int mx[sq];
int cur = 1;

void add(int x){
	int cur = ::cur;
	while(cur > 1 and mx[cur] < a[x] and c[x] >= (int)q[cur].size()) x[c]-=q[cur].size() , cur--;
	while(q[cur].size() and c[x] and a[q[cur].back()] < a[x])c[x] -- , q[0].pb(q[cur].back()),q[cur].pop_back();
	q[cur].pb(x);
	mx[cur] = max(mx[cur] , a[x]);
	while(q[0].size())q[cur].pb(q[0].back()) , q[0].pop_back();
}

void rebuild(){
	for(int i = 1 ; i <= cur ; i ++){
		for(int x : q[i])
			q[0].pb(x);
		q[i].clear();
	}
	ms(mx , 0);
	cur = 1;
	while(q[0].size()){
		int x = q[0].front();
		q[0].pop_front();
		q[cur].pb(x);
		mx[cur] = max(mx[cur] , a[x]);
		if(q[cur].size() == 300)cur++;
	}
}

void solve(){
	for(int i = 1 ; i <= cur ; i ++)
		for(int x : q[i])
			cout << x << ' ';
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] >> c[i];
		add(i);
		if(i%300 == 0)rebuild();
	}
	solve();
    return(0);
}
