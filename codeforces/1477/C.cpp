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

const int maxn = 5100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct point{
	ll x , y , id;
}p[maxn] , cur;

ll dist(point a , point b){
	return((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int n;

int32_t main(){
	migmig;
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> p[i].x >> p[i].y , p[i].id = i + 1;
	for(int i = 0 ; i < n ; i ++){
		cout << p[i].id << ' ', cur = p[i];
		sort(p + i + 1 , p + n , [](point a , point b){return(dist(a , cur) > dist(b , cur));});
	}
	return(0);
}
