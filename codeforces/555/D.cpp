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

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;

vector < int > x;

int X[maxn];

map < int , int > mp;

bool chk(int v , int l){
	if(x[v + 1] - x[v] <= l)return(1);
	if(x[v] - x[v - 1] <= l)return(1);
	return(0);
}

int R(int a , int l){
	return((upper_bound(x.begin() , x.end() , x[a] + l) - x.begin()) - 1);
}

int L(int a , int l){
	return(lower_bound(x.begin() , x.end() , x[a] - l) - x.begin());
}

int gol(int a , int l) ;

int gor(int a , int l){
	if(R(a , l) == L(a , l))return(a);
	if(x[a+1] - x[a] > l)return(gol(a , l));
	int nxt = R(a , l);
	int d = x[nxt] - x[a];
	int t = l/d;
	l%=d;
	if(t%2)return(gol(nxt , l));
	return(gor(a , l));
}

int gol(int a , int l){
	if(R(a , l) == L(a , l))return(a);
	if(x[a] - x[a-1] > l)return(gor(a , l));
	int nxt = L(a , l);
	int d = x[a] - x[nxt];
	int t = l/d;
	l%=d;
	if(t%2)return(gor(nxt, l));
	return(gol(a , l));
}

int32_t main(){
    migmig;
	cin >> n >> m;
	x.pb(-2e9-1);
	for(int i = 1 ; i <= n ; i ++){
		cin >> X[i];
		x.pb(X[i]);
		mp[X[i]] = i;
	}
	x.pb(2e9+1);
	sort(x.begin() , x.end());
	while(m --){
		int a , l;
		cin >> a >> l;
		a = lower_bound(x.begin() , x.end() , X[a]) - x.begin();
		if(R(a , l)!=a){
			int d = x[R(a , l)] - x[a];
			a = R(a , l);
			l-=d;
		}
		cout << mp[x[gor(a , l)]] << endl;
	}
    return(0);
}
