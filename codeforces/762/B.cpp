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

int a , b , c;
int t;
ll ans = 0;
int cnt = 0;
vector < pii > vec;

int32_t main(){
    migmig;
	cin >> a >> b >> c;
	cin >> t;
	while(t--){
		int c;
		string s;
		cin >> c >> s;
		if(s == "USB")vec.pb({c , 0});
		else vec.pb({c,  1});
	}
	sort(vec.begin() , vec.end());
	reverse(vec.begin() , vec.end());
	while(vec.size()){
		auto [cost , type] = vec.back();
		vec.pop_back();
		if(type){
			if(b){
				b-- , cnt ++ , ans += cost;
			}
			else if(c){
				c-- , cnt++ , ans += cost;
			}
		}
		else{
			if(a){
				a -- , cnt ++ , ans += cost;
			}
			else if(c){
				c-- , cnt++ , ans += cost;
			}
		}
	}
	cout << cnt << ' ' << ans;
    return(0);
}
