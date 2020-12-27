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

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
ll t[maxn] , x[maxn];

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		for(int i = 0 ; i < n ; i ++ )
			cin >> t[i] >> x[i];
		ll lst = 0;
		ll tpos = 0 , ttime = 0;
		t[n] = 1e18;
		int cnt = 0;
		for(int i = 0 ; i < n ; i ++){
			if(ttime <= t[i]){
				if(abs(x[i] - tpos) <= t[i + 1] - t[i])cnt ++ ;
				ttime = t[i];
				ttime += abs(x[i] - tpos);
				lst = tpos;
				tpos = x[i];
			}
			else{
				ll l = ttime - t[i];
				ll r = ttime - t[i + 1];
				if(lst > tpos){
					if(x[i] > lst or x[i] < tpos)continue;
					//        tpos      <<----    lst
					ll L = tpos + l;
					ll R = ((r >= 0) ? tpos + r : tpos);
					if(R <= x[i] and x[i] <= L)cnt++;
				}
				if(lst < tpos){
					if(x[i] < lst or x[i] > tpos)continue;
					//        lst      ---->>    tpos
					ll L = tpos - l;
					ll R = ((r >= 0) ? tpos - r : tpos);
					if(L <= x[i] and x[i] <= R)cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
    return(0);
}
