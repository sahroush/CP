//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 30010;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;

#define f first
#define s second

pii h[maxn];
pii w[maxn];

int bad[maxn];

ll ans[maxn];

ll calc(int i , int j){
	if(bad[w[j].s] == h[i].s) return(-1e17);
	return(h[i].f * 1LL * w[j].f);
}

ll solve(){
	ans[1] = calc(1 , 1);
	ans[2] = max(calc(1 , 1) + calc(2 , 2) , calc(1 , 2) + calc(2 , 1));
	for(int i = 3 ; i <= n ; i ++){
		ans[i] = -1e17;
		ans[i] = max(ans[i] , calc(i , i) + ans[i - 1]);
		
		ans[i] = max(ans[i] , calc(i , i - 1) + calc(i - 1 , i) + ans[i - 2]);
		
		ans[i] = max(ans[i] , calc(i , i - 2) + calc(i - 1 , i - 1) + calc(i - 2 , i) + ans[i - 3]);
		ans[i] = max(ans[i] , calc(i , i - 2) + calc(i - 1 , i) + calc(i - 2 , i - 1) + ans[i - 3]);
		
		ans[i] = max(ans[i] , calc(i , i - 1) + calc(i - 1 , i - 2) + calc(i - 2 , i) + ans[i - 3]);

	}
	return(ans[n]);
}

int32_t main(){
    migmig;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> w[i].f , w[i].s = i;
	for(int i = 1 ; i <= n ; i ++)
		cin >> h[i].f , bad[i] = i , h[i].s = i;
	sort(h + 1 , h + n + 1);
	sort(w + 1 , w + n + 1);
	reverse(h + 1 , h + n + 1);
	reverse(w + 1 , w + n + 1);
	while(q -- ){
		int a , b;
		cin >> a >> b;
		swap(bad[a] , bad[b]);
		cout << solve() << endl;
	}
    return(0);
}
