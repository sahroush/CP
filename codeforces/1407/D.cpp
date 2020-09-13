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

int h[maxn];
int n;
stack < int > mn , mx;
int ans[maxn];
vector < int > adj[maxn];

int32_t main(){
    migmig
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> h[i];
		ans[i] = i - 1;
		while(mn.size() and h[mn.top()] > h[i])
			mn.pop();
		if(mn.size())adj[mn.top()].pb(i);
		mn.push(i);
		while(mx.size() and h[mx.top()] < h[i])
			mx.pop();
		if(mx.size())adj[mx.top()].pb(i);
		mx.push(i);
	}
	reverse(h+1 , h + n + 1);
	while(mn.size())mn.pop();
	while(mx.size())mx.pop();
	for(int i = 1 ; i <= n ; i ++){
		while(mn.size() and h[mn.top()] > h[i])
			mn.pop();
		if(mn.size())adj[n+1 - i].pb(n+1-mn.top());
		mn.push(i);
		while(mx.size() and h[mx.top()] < h[i])
			mx.pop();
		if(mx.size())adj[n+1 - i].pb(n+1-mx.top());
		mx.push(i);
	}
	for(int i = 1 ; i <= n ; i ++)
		for(auto u : adj[i])
			ans[u] = min(ans[u] , ans[i]+1);
	cout << ans[n];
    return(0);
}