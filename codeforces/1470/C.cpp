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
//#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;

int ask(int x){
	cout << "? " << x << endl;
	cin >> x;
	return(x);
}

void solve(int l , int r){
	for( ; l <= r ; l ++)
		if(ask(l) == k){
			cout << "! ";
			dokme(l);
		}
}

void evlos(int l , int r){
	for( ; l >= r ; l --)
		if(ask(l) == k){
			cout << "! ";
			dokme(l);
		}
}

int32_t main(){
    migmig;
	cin >> n >> k;
	int sq = sqrt(n);
	for(int i = 0 ; i <= sq ; i ++)ask(1);
	int id = 1 , l = -1 , r = -1;
	while(min(l , r) == -1){
		int res = ask(id);
		if(res < k)
			l = id;
		if(res >  k)
			r = id;
		id = (id + sq)%n + 1;
	}
	if(l <= r){
		solve(l , r);
	}
	solve(1 , r);
	evlos(n , l);
    return(0);
}
