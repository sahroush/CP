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

int n;
string s;

int32_t main(){
    migmig;
	cin >> n;
	cin >> s;
	int x = -1 , y = -1;
	int ans = 1;
	for(int i = 0 ; i < n ; i ++){
		if(s[i] == 'L'){
			if(x == 1){
				x = -1 , y = -1;
				ans++;
			}
			x = 0;
		}
		if(s[i] == 'R'){
			if(x == 0){
				x = -1 , y = -1;
				ans++;
			}
			x = 1;
		}
		if(s[i] == 'U'){
			if(y == 0){
				x = -1 , y = -1;
				ans++;
			}
			y = 1;
		}
		if(s[i] == 'D'){
			if(y == 1){
				x = -1 , y = -1;
				ans++;
			}
			y = 0;
		}
	}
	cout << ans;
    return(0);
}
