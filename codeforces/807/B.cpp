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

ll p , x , y;

bool chk(ll s){
	/*
	i := (s div 50) mod 475
	repeat 25 times:
    i := (i * 96 + 42) mod 475
    print (26 + i)
    */
    s = (s/50)%475;
    for(int i = 0 ; i < 25 ; i ++){
		s = (s * 96LL + 42) % 475;
		if(s + 26 == p)return(1);
	}
	return(0);
}

int32_t main(){
    migmig;
	cin >> p >> x >> y;
	for(int i = 0 ; i < 1000 ; i ++){
		for(int j = 0 ; j < 1000 ; j ++ ){
			ll s = x + i * 100 - j * 50;
			if(s < y)continue;
			if(chk(s))
				dokme(i);
		}
	}
    return(0);
}