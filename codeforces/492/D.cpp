/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef float ld;
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

int q;
ll x , y;
int ans[maxn];

int32_t main(){
    migmig;
    cin >> q;
	cin >> x >> y;
	ans[0] = 3;
	ld cx = 0 , cy = 0;
	for(int i = 1 ; i <= x + y ; i ++){
		if((cx + 1)/ld(x) > (cy + 1)/ld(y))ans[i] = 1 , cy++;
		else if((cx + 1)/ld(x) < (cy + 1)/ld(y))ans[i] = 2 , cx++;
		else ans[i] = 3 , cx++ , cy++ , i ++ , ans[i] = 3;
	}
	while(q -- ){
		ll n;
		cin >> n;
		n%=(x+y);
		if(ans[n] == 3)
			cout << "Both" << endl;
		else if(ans[n] == 1)
			cout << "Vova" << endl;
		else
			cout << "Vanya" << endl;
	}
    return(0);
}
