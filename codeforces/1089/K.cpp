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

const int maxn = 1e6+10;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll mx[maxn<<2] , lazy[maxn<<2];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void add(int L , int R , ll x , int v = 1 , int l = 0 , int r = maxn){
	if(r <= L or R <= l)return;
	if(L <= l and r <= R){
		lazy[v] += x;
		return;
	}
	add(L , R , x , lc , l , mid);
	add(L , R , x , rc , mid , r);
	mx[v] = max(mx[lc] + lazy[lc] , mx[rc] + lazy[rc]);
}

ll get(int L, int R, int v = 1, int l = 0, int r = maxn){
	if(r <= L or R <= l)return(-1e15);
	if(L <= l and r <= R)return(mx[v] + lazy[v]);
	return(max(get(L , R , lc , l , mid) , get(L , R , rc , mid , r)) + lazy[v]);
}

int n;
pii q[maxn];

int32_t main(){
	migmig;
	cin >> n;
	for(int i = 0 ; i < maxn ; i ++)add(i , i + 1 , i - maxn);
	for(int i = 0 ; i < n ; i ++){
		char t;
		cin >> t;
		if(t == '?'){
			int ti;
			cin >> ti;
			cout << get(0 , ti + 1) - get(ti+1 , ti+2) + 1 << endl;
		}
		if(t == '+'){
			int ti , d;
			cin >> ti >> d;
			q[i] = {ti , d};
			add(0 , ti + 1 , d);
		}
		if(t == '-'){
			int pos;
			cin >> pos;
			auto [ti , d] = q[pos-1];
			add(0 , ti + 1 , -d);
		}
	}
	return(0);
}
