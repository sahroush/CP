//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 100;
const ll base = 196613;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)


int n , m;
int a[maxn] , b[maxn], p[maxn] , cnt;
ll pw[maxn], h , sum, seg[maxn<<2] , sz[maxn<<2];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void on(int pos , int v = 1 , int l = 1 , int r = m + 1){
	sz[v]++ , seg[v] = b[l] * base;
	if(r - l == 1)
		return;
	if(pos < mid)
		on(pos , lc , l , mid);
	else
		on(pos , rc , mid , r);
	sz[v] = sz[lc] + sz[rc];
	seg[v] = seg[lc] + seg[rc] * pw[sz[lc]];
}

void off(int pos , int v = 1 , int l = 1 , int r = m + 1){
	sz[v]-- , seg[v] = 0;
	if(r - l == 1)
		return;
	if(pos < mid)
		off(pos , lc , l , mid);
	else
		off(pos , rc , mid , r);
	sz[v] = sz[lc] + sz[rc];
	seg[v] = seg[lc] + seg[rc] * pw[sz[lc]];
}


int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= m ; i ++)
		cin >> b[i] , p[b[i]] = i;
	pw[0] = 1;
	for(int i = 1 ; i < maxn ; i ++)
		pw[i] = pw[i-1] * base;
	for(int i = 1 ; i <= n ; i ++)
		h += a[i] * pw[i] , sum += pw[i];
	for(int i = 1 ; i < n ; i ++)
		on(p[i]);
	for(int i = n ; i <= m ; i ++ , h += sum){
		on(p[i]);
		cnt += (h == seg[1]);
		off(p[i - n + 1]);
	}
	cout << cnt;
	return(0);
}
