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
//#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;

int ask(int l,  int r){
	if(l == r)return(l+1);
	cout << "? " << l << ' ' << r << endl;
	cin >> r;
	return(r);
}

int solve(int l , int r , int lst){
	if(r == l)
		return(l);
	if(r - l == 1){
		return((l == lst) ? r : l);
	}
	int mid = (l + r) / 2;
	if(lst >= mid){
		int res = ask(mid , r);
		if(res == lst){
			return(solve(mid , r , lst));
		}
		else{
			return(solve(l , mid - 1 , ask(l , mid - 1)));
		}
	}
	else{
		int res = ask(l , mid);
		if(res == lst){
			return(solve(l , mid , lst));
		}
		else
			return(solve(mid+1 , r , ask(mid+1 , r)));
	}
}

int32_t main(){
	migmig;
	cin >> n;
	int l = 1 , r = n;
	int ans = solve(l , r , ask(l , r));
	cout << "! " << ans;
	return(0);
}
