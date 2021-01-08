//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 1e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
vector < int > und;
const int sq = 1000;
int cnt[maxn] , sz = 0;

void add(int x){
	sz+=((++cnt[x])==1) , und.pb(x);
}

void reset(){
	for(int x : und)cnt[x] = 0;
	sz = 0;und.clear();
}

int chk(int x){
	int ans = 1;
	for(int i = 1;  i <= n ; i ++){
		add(a[i]);
		if(sz > x){
			ans++;
			reset();
			add(a[i]);
		}
	}
	reset();
	return(ans);
}	

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= min(sq,n) ; i ++)
		cout << chk(i) << ' ';
	for(int l = sq + 1 ; l <= n ;){
		int r = l;
		int res = chk(l);
		for(int i = 20 ; i >= 0 ; i --)
			if(r + (1 << i) <= n)	
				if(chk(r + (1 << i)) == res)
					r += (1 << i);
		for( ; l <= r ; l ++)
			cout << res << ' ';
	}
    return(0);
}
