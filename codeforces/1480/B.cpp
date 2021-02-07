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

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
ll a , b;
ll h[maxn] , p[maxn];
ll srt[maxn];

bool cmp(int i , int j){
	return(p[i] < p[j]);
}

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> a >> b >> n;
		for(int i = 0 ; i < n ; i ++)
			cin >> p[i];
		for(int i = 0 ; i < n ; i ++)
			cin >> h[i] , srt[i] = i;
		sort(srt , srt + n , cmp);
		int lst = 0;
		for(int i = 0 ; i < n ; i ++){
			ll l = 0 , r = 1e9 + 100;
			while(r - l > 1){
				ll mid = ( l + r ) / 2;
				if(h[srt[i]] - a * mid <= 0){
					r = mid;
				}
				else{
					l = mid;
				}
			}
			b -= p[srt[i]] * r;
			h[srt[i]] -= r * a;
			assert(h[srt[i]] <= 0);
			if(b <= 0){
				b += p[srt[i]];
				h[srt[i]] += a;
				if(b >= 1 and h[srt[i]] - a < 1){
					lst = i + 1;
					break;
				}
				else{
					lst = i;
					break;
				}
			}
			lst = i + 1;
		}
		cout << ((lst == n) ? "YES" : "NO") << endl;
	}
    return(0);
}
