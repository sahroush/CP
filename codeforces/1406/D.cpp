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

const ll maxn  = 2e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int q;
ll a[maxn];
ll sum[2];
ll A[maxn];

bool p(ll x){
	return(x >= 0);
}

bool chk(ll mid){
	ll c = mid;
	ll b = a[1] - mid + sum[1];
	ll mx = max(c , b);
	return(mx <= mid);
}

void bs(){
	ll l = -1e18 , r = 1e18;
	while(r - l > 1){
		ll mid = (l + r)/2;
		if(chk(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
}

int32_t main(){
    migmig
	cin >> n;
	for(int i = 1;  i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i < n ; i ++)
		A[i] = a[i+1] - a[i];
	for(int i = 1 ; i < n ; i ++)
		sum[p(A[i])]+=abs(A[i]);
	bs();
	cin >> q;
	while(q --){
		ll l , r , x;
		cin >> l >> r >> x;
		if(l > 1)
			sum[p(A[l-1])]-= abs(A[l-1]),
			A[l-1]+=x,
			sum[p(A[l-1])]+= abs(A[l-1]);
		if(r < n)
			sum[p(A[r])]-= abs(A[r]),
			A[r]-=x,
			sum[p(A[r])]+= abs(A[r]);
		if(l == 1)	
			a[1]+=x;
		bs();
	}
    return(0);
}