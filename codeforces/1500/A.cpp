/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const int sq = 2000;
int n;
int a[maxn];
int cnt[maxn];
vector < int > duo;
set < int > st;
vector < int > fuck;

vector < pii > sum[5000100];

void solve(){
	n = fuck.size();
	for(int i = 0 ; i < n ; i ++){
		for(int j = i + 1 ; j < n ; j ++){
			sum[a[fuck[i]] + a[fuck[j]]].pb({fuck[i] , fuck[j]});
		}
	}
	for(int i = 0 ; i < 5000100 ; i ++){
		if(sum[i].size() >= 2){
			cout << "YES" << endl;
			auto [x, y] = sum[i][0];
			cout << x << ' ' << y << ' ';
			auto [u, v] = sum[i][1];
			cout << u << ' ' << v << ' ';
			exit(0);
		}
	}
	dokme("NO");
}


int32_t main(){
	migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		cnt[a[i]]++;
		if(cnt[a[i]] == 4){
			cout << "YES" << endl;
			for(int j = 1 ; j <= i ; j ++)if(a[j] == a[i])
				cout << j << ' ';
			return(0);
		}
	}
	for(int i = 1 ; i < maxn ; i ++)
		if(cnt[i] >= 2){
			duo.pb(i);
		}
	if(duo.size() >= 2){
		cout << "YES" << endl;
		int x = duo[0] , y = duo[1];
		vector < int > u, v;
		for(int i = 1 ; i <= n ; i ++)if(a[i] == x)u.pb(i);
		else if(a[i] == y)v.pb(i);
		cout << u[0] << ' ' << v[0] << ' ' << u[1] << ' ' << v[1];
		return(0);
	}
	if(duo.size()){
		int x = duo[0];
		int u = - 1, v = -1;
		for(int i = 0 ; i < maxn ; i ++){
			if(cnt[i] and i ^ x and 2 * x - i > 0 and 2 * x - i < maxn and cnt[2*x - i]){
				u = i , v = 2 * x - i;
			}
		}
		if(u != -1){
			cout << "YES" << endl;
			vector < int > ans[3];
			for(int i = 1 ; i <= n ; i ++){
				if(a[i] == x)ans[0].pb(i);
				if(a[i] == u)ans[1].pb(i);
				if(a[i] == v)ans[2].pb(i);
			}
			cout << ans[0][0] << ' ' << ans[0][1] << ' ' << ans[1][0] << ' ' << ans[2][0];
			return(0);
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		if(st.count(a[i]))continue;
		st.insert(a[i]);
		fuck.pb(i);
		if(fuck.size() == sq)break;
	}
	solve();
	return(0);
}
