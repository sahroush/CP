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
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 5e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
int a[maxn];
bool block[maxn];

int fen[maxn];

vector < int > undo;

void add(int x , int pos){
	for(pos += 5 ; pos < maxn ; pos += pos & -pos)
		fen[pos] = max(fen[pos] , x) , undo.pb(pos);
}

int get(int pos){
	int ans = 0;
	for(pos += 5 ; pos ; pos -= pos & -pos)
		ans = max(ans , fen[pos]);
	return(ans);
}

void clear(){
	for(auto x : undo)fen[x] = 0;
	undo.clear();
	undo.reserve((1 << 5));
}

vector < int > comp;

int com(int x){
	return(lower_bound(comp.begin() , comp.end() , x) - comp.begin());
}

int solve(int l , int r){
	clear();
	for(int i = l ; i <= r ; i ++){
		if(a[i] >= a[l])
			add(get(a[i]) + 1 , a[i]);
	}
	return(r - l + 1 - get(a[r]));
}

int32_t main(){
    migmig;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	a[0] = -1e9 , a[n+1] = 2e9;
	for(int i = 1 ; i <= k ; i ++)
	{int x ; cin >> x ; block[x] = 1;}
	block[0] = block[n+1] = 1;
	int cur = -2e9;
	for(int i = 1 ; i <= n ; i ++){
		cur++;
		if(cur > a[i] and block[i])dokme(-1);
		else if (block[i])cur = a[i];
	}
	for(int i = 0 ; i <= n + 1 ; i ++)a[i]-=i,comp.pb(a[i]);
	sort(comp.begin() , comp.end());
	comp.erase(unique(comp.begin() , comp.end()) , comp.end());
	for(int i = 0 ; i <= n + 1 ; i ++)a[i] = com(a[i]);
	int ans = 0;
	int l = 0 , r = 0;
	while(r <= n+1){
		if(r == l)r++;
		else if(!block[r])r++;
		else if(!block[l])l++;
		else ans+=solve(l , r) , l++;
	}
	cout << ans;
    return(0);
}
