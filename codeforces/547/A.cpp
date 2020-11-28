//*
#pragma GCC optimize("O2")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 4e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int m;
int h[2];
int a[2];
int x[2];
int y[2];

int c[maxn][2];

int32_t main(){
    migmig;
	cin >> m;
	for(int i = 0 ; i < 2 ; i ++)
		cin >> h[i] >> a[i] >> x[i] >> y[i] , c[0][i] = h[i];
	for(int i = 1 ; i <= 2*m ; i ++)
		for(int j = 0 ; j < 2 ; j ++)
			c[i][j] = (c[i - 1][j] * 1LL * x[j] + y[j])%m;
	ll d[2] = {-1 , -1};
	ll pos[2] = {-1 , -1};
	for(int i = 0 ; i <= 2*m ; i ++)
		for(int j = 0 ; j < 2 ; j ++)
			if(pos[j] == -1 and c[i][j] == a[j])pos[j] = i;
	for(int i = 0 ; i <= 2*m ; i ++)
		for(int j = 0 ; j < 2 ; j ++)
			if(c[i][j] == c[pos[j]][j] and d[j] == -1 and i > pos[j])d[j] = i - pos[j];	
	if(min(pos[0] , pos[1]) < 0)dokme(-1);
	for(int i = 0 ; i <= 3e6 ; i ++){
		while(pos[0] < pos[1] and d[0] > 0)pos[0]+=d[0];
		while(pos[1] < pos[0] and d[1] > 0)pos[1] += d[1];
		if(pos[0] == pos[1])dokme(pos[1]);
	}
	dokme(-1);
    return(0);
}
