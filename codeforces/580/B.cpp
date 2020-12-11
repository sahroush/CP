/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
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

int n , d;

#define f first
#define s second

pii a[maxn];


int32_t main(){
    migmig;
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i].f >> a[i].s;
	sort(a + 1 , a + n + 1);
	int l = 1, r = 1;
	int ans = a[1].s;
	int sum = a[1].s;
	while(r != n){
		r++;
		sum += a[r].s;
		while(a[r].f - a[l].f >= d)sum-=a[l].s , l ++;
		ans = max(ans , sum);
	}
	cout << ans << endl;
    return(0);
}
