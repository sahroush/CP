/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
int l[maxn] , r[maxn];
int a[maxn];
int ans[maxn];

int seg[maxn*4];
int lazy[maxn*4];

void shift(int v , int l , int r){	
	if(!lazy[v])return;
	seg[v] = lazy[v];
	if(r - l > 1)
		lazy[2*v] = lazy[2*v + 1] = lazy[v];
	lazy[v] = 0;
}

void update(int L , int R ,int x, int v = 1, int l = 1, int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		lazy[v] = x;
		shift(v , l , r);
		return;
	}
	int mid = (l + r)/2;
	update(L , R , x , 2*v , l , mid);
	update(L , R , x , 2*v+1 , mid , r);
}

int get(int pos , int v = 1, int l = 1, int r = n + 1){
	shift(v , l , r);
	if(r - l == 1)
		return(seg[v]);
	int mid = (l + r)/2;
	if(pos < mid)
		return(get(pos , 2*v , l , mid));
	else
		return(get(pos , 2*v + 1, mid , r));
}

int32_t main(){
    migmig;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	if(*max_element(a + 1, a + n + 1) == 0){
		cout << "YES" << endl;
		for(int i = 1 ; i <= n ; i ++)
			cout << q << ' ';
		return(0);
	}
	if(*max_element(a +1 , a + n + 1) < q){
		bool ok = 0;
		for(int i = 1 ; i <= n ; i ++)
			if(a[i] == 0){
				a[i] = q , ok = 1;break;}
		if(!ok)
			dokme("NO");
	}
	for(int i = 1 ; i <= n ; i ++)
		l[max(a[i] , 1)] = ((l[max(a[i] , 1)])?l[max(a[i] , 1)] : i),
		r[max(a[i] , 1)] = i;
	for(int i = 1 ; i <= q ; i ++)
		update(l[i] , r[i]+1 , i);
	for(int i = 1 ; i <= n ; i ++)
		ans[i] = get(i);
	for(int i = 1 ; i <= n ; i ++)
		if(ans[i]!=a[i] and a[i])
			dokme("NO");
	cout << "YES" << endl;
	for(int i = 1;  i <= n ; i ++)
		cout << ans[i] << ' ';
    return(0);
}
