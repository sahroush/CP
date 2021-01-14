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

const ll maxn = 2e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , t;
string s;
int prt[maxn];
int mn[maxn] , mx[maxn];
int rmx[maxn], rmn[maxn];


void prep(){
	prt[n + 1] = 0;
	for(int i = 1 ; i <= n ; i ++)
		prt[i] = prt[i - 1] + ((s[i] == '+') ? 1 : -1),
		mn[i] = min(mn[i - 1] , prt[i]),
		mx[i] = max(mx[i - 1] , prt[i]);
	rmx[n + 1] = rmn[n + 1] = 0;
	int MX = -1e9 , MN = 1e9;
	for(int i = n ; i >= 1 ; i --){
		MX = max(MX , prt[i]);
		MN = min(MN , prt[i]);
		rmx[i] = MX - prt[i - 1];
		rmn[i] = MN - prt[i - 1];
	}
}

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n >> t;
		cin >> s;
		s = "5" + s;
		prep();
		while(t -- ){
			int l , r;
			cin >> l >> r;
			l -- , r ++;
			int L = 0 , R = 0;
			L = min(L , mn[l]);
			R = max(R , mx[l]);
			int x = prt[l];
			L = min(L , x + rmn[r]);
			R = max(R , x + rmx[r]);
			cout << R - L + 1 << endl;
		}
	}
    return(0);
}
