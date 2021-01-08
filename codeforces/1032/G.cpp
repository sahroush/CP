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

const ll maxn = 3e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const int lg = 20;
int a[maxn];
int b[maxn] , c[maxn];
int Log[maxn]; 
int n;
int l[lg][maxn];
int r[lg][maxn];

struct RMQ{
	int rmq[lg][maxn] , d , a[maxn];
	int mx(int x , int y){
		return((a[x] < a[y]) ? y : x);
	}
	void init(int* arr , int n , int D){
		d = D;
		for(int i = 1; i <= n ; i ++)
			rmq[0][i] = i , a[i] = d * arr[i];
		for(int j = 1 ; j <= Log[n] ; j ++)
			for(int i = 1 ; i + (1 << j) - 1 <= n ; i ++)
				rmq[j][i] = mx(rmq[j - 1][i] , rmq[j - 1][i + (1 << (j - 1))]);
	}
	int query(int l , int r){
		int sz = Log[r - l + 1];
		return(mx(rmq[sz][l] , rmq[sz][r - (1 << sz) + 1]));
	}
} L , R;

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 2 ; i < maxn ; i ++)
		Log[i] = Log[i >> 1] + 1;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i],
		a[i + n] = a[i + 2*n] = a[i];
	if(n == 1)dokme(0);
	for(int i = 1 ; i <= 3*n ; i ++)
		b[i] = max(1 , i - a[i]) ,
		c[i] = min(3*n , i + a[i]);
	for(int i = 0 ; i <= Log[3 * n] ; i ++)
		r[i][3*n] = 3*n , l[i][1] = 1;
	for(int i = 1 ; i <= 3 * n ; i ++)
		l[0][i] = b[i] , r[0][i] = c[i];
	R.init(r[0] , n * 3 , 1);
	L.init(l[0] , n * 3 , -1);
	for(int i = 1 ; i <= Log[3 * n] ; i ++)
		for(int j = 1 ; j <= 3 * n ; j ++){
			int pl = L.query(l[i - 1][j] , r[i - 1][j]),
				pr = R.query(l[i - 1][j] , r[i - 1][j]); 
			l[i][j] = min(l[i - 1][pl] , l[i - 1][pr]),
			r[i][j] = max(r[i - 1][pl] , r[i - 1][pr]);
		}
	for(int j = n + 1 ; j <= n * 2 ; j ++){
		int pl = j , pr = j;
		int ans = 1;
		for(int i = Log[3 * n] ; i >= 0 ; i --){
			if(max(r[i][pl] , r[i][pr]) - min(l[i][pl] , l[i][pr]) + 1 >= n)continue;
			int resl = L.query(l[i][pl] , r[i][pr]);
			int resr = R.query(l[i][pl] , r[i][pr]);
			pl = resl , pr = resr;
			ans += (1 << i);
		}
		cout << ans << ' ';
	}
    return(0);
}