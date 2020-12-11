//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k ;
#define l first
#define r second
pii a[maxn];

bool chk(int x){
	vector < pii > vec;
	for(int i = 1 ; i <= n ; i ++)
		vec.pb({a[i].l , 0}) , vec.pb({max(a[i].r - x + 2, a[i].l) , 1});
	sort(vec.begin() ,vec.end());
	int cur = 0;
	for(int i = 0;  i < vec.size() ; i ++){
		int j = i;
		while(vec[j].l == vec[i].l){
			if(vec[j].r)cur--;
			else cur++;
			j++;
		}
		i = j - 1;
		if(cur >= k)return(1);
	}
	return(0);
}

void solve(int x){
	if(x == 0){for(int i = 1 ; i <= k ; i ++)cout << i << ' '; return;}
	vector < pii > vec;
	for(int i = 1 ; i <= n ; i ++)
		vec.pb({a[i].l , 0}) , vec.pb({max(a[i].r - x + 2, a[i].l) , 1});
	sort(vec.begin() ,vec.end());
	int cur = 0 , pos;
	for(int i = 0;  i < vec.size() ; i ++){
		int j = i;
		while(vec[j].l == vec[i].l){
			if(vec[j].r)cur--;
			else cur++;
			j++;
		}
		i = j - 1;
		if(cur >= k)pos = vec[i].l;
	}
	for(int i = 1 ; i <= n ; i ++){
		int L = a[i].l;
		int R = max(a[i].r - x + 2, a[i].l);
		if(pos >= L and pos < R)
			cout << i << ' ' , k--;
		if(k == 0 ) return;	
	}
}

int32_t main(){
    migmig;
    //prt.max_load_factor(0.1);
	cin >> n >> k;
	for(int i = 1 ; i <= n;  i ++)
		cin >> a[i].l >> a[i].r;
	int l = 0 , r = 1e10;
	while(r - l > 1){
		int mid = (l + r)/2;
		if(chk(mid))
			l = mid;
		else 
			r = mid;
	}
	cout << l << endl;
	solve(l);
    return(0);
}
