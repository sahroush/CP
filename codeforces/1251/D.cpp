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

int q;
int n;
ll l[maxn] , r[maxn], s;

bool chk(ll x){
	vector < int > a , b;
	for(int i = 1 ; i <= n ; i ++)
		if(r[i] >= x)a.pb(i);
		else b.pb(i);
	if((int)b.size() > n/2)return(0);
	ll sum = s;
	for(int i : b)sum -= l[i];
	int rmn = n / 2 - (int)b.size();
	sort(a.begin() , a.end() , [](int i , int j){return(l[i] < l[j]);});
	for(int i = 0 ; i < rmn ; i ++)	
		sum -= l[a[i]];
	for(int i = rmn ; i < (int)a.size() ; i ++)	
		sum -= max(x , l[a[i]]);
	return(sum >= 0);
}

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n >> s;
		for(int i = 1 ; i <= n ; i ++)
			cin >> l[i] >> r[i];
		ll L = 0 , R = 1e15;
		while(R - L > 1){
			ll mid = (L + R) / 2;
			if(chk(mid))
				L = mid;
			else
				R = mid;
		}
		cout << L << endl;
	}
	return(0);
}
