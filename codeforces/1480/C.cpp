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

int n;
int cnt = 0;

int ask(int x){
	if(x == 0 or x == n + 1)return(n + 1);
	cout << "? " << x << endl;
	cin >> x;
	cnt++;
	assert(cnt <= 100);
	return(x);
}

void chk(int l){
	cout << "! " << l << endl;
	exit(0);
}

int32_t main(){
    migmig;
	cin >> n;
	if(n == 1){
		cout << "! 1" << endl;
		return(0);
	}
	if(n == 1){
		chk(1);
		return(0);
	}
	int l = 1 , r = 1+n;
	while(r - l > 1){
		int mid = (l + r) / 2;
		int a = ask(mid - 1) , b = ask(mid) , c = ask(mid + 1);
		if(b < a and b < c)chk(mid);
		if(a > b){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	chk(l);
    return(0);
}
