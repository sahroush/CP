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

int q;
int d;

vector < int > vec;

bool prime[maxn];

int32_t main(){
    migmig;
	cin >> q;
	for(int i = 2 ; i < maxn ; i ++)
		prime[i] = 1;
	for(int i = 2 ; i < maxn ; i ++){
		if(!prime[i])continue;
		for(int j = i + i ; j < maxn ; j += i)
			prime[j] = 0;
		vec.pb(i);
	}
	while(q -- ){
		cin >> d;
		int x = upper_bound(vec.begin() , vec.end() , d) - vec.begin();
		int y = lower_bound(vec.begin() , vec.end() , vec[x] + d) - vec.begin();
		cout << 1LL * vec[x] * vec[y] << endl;
	}




    return(0);
}
