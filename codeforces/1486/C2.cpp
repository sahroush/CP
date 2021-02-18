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
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

void dokme(int x){
	cout << "! " << x << endl;
	exit(0);
}

int n;

int ask(int l,  int r){
	cout << "? " << l << ' ' << r << endl;
	cin >> r;
	return(r);
}

int right(int pos){
	//mx2 ... mx
	int l = 0 , r = n - pos;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(ask(pos , pos + mid) == pos){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	return(pos + r);
}

int left(int pos){
	//mx ... mx2
	int l = 0 , r = pos - 1;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(ask(pos - mid , pos) == pos){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	return(pos - r);
}

int32_t main(){
	migmig;
	cin >> n;
	int l = 1 , r = n;
	int mx2 = ask(l , r);
	if(mx2 == 1){
		dokme(right(mx2));
	}
	if(mx2 == n){
		dokme(left(mx2));
	}
	if(ask(l , mx2) == mx2){
		dokme(left(mx2));
	}
	dokme(right(mx2));
	return(0);
}
