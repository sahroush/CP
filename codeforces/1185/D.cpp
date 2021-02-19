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
typedef pair<ll , ll> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll a[maxn];
set < ll > st;

const ll inf = 1e18;

pii cnt[3];

int sz(){
	int res = 0;
	for(int i = 0 ; i < 3 ; i ++)
		if(cnt[i].second)res++;
	return(res);
}



bool chk(int pos){
	if(pos == 1){
		ll val = a[2] - a[1];
		for(int i = 0 ; i < 3 ; i ++)	
			if(cnt[i].first == val){
				cnt[i].second--;
				if(sz() <= 1)return(1);
				cnt[i].second++;
				return(0);
			}
	}
	if(pos == n){
		ll val = a[n] - a[n - 1];
		for(int i = 0 ; i < 3 ; i ++)	
			if(cnt[i].first == val){
				cnt[i].second--;
				if(sz() <= 1)return(1);
				cnt[i].second++;
				return(0);
			}
	}
	ll v = a[pos + 1] - a[pos];
	ll vl = a[pos] - a[pos - 1];
	ll x = a[pos + 1] - a[pos - 1];
	for(int i = 0 ; i < 3 ; i ++){
		for(int j = 0 ; j < 3 ; j ++){
			if(cnt[i].first == v and cnt[j].first == vl){
				cnt[i].second -- , cnt[j].second --;
				for(int k = 0 ; k < 3 ; k ++){
					if(cnt[k].first == x){
						cnt[k].second++;
						if(sz() <= 1)return(1);
						cnt[k].second--;
					}
				}
				cnt[i].second ++ , cnt[j].second ++;
			}
		}
	}
	return(0);
}

int srt[maxn] , ord[maxn];

int32_t main(){
	migmig;
	cin >> n;
	if(n <= 3)dokme(1);
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= n ; i ++)srt[i] = i;
	sort(srt + 1 , srt + 1 + n , [](int i , int j){return(a[i] < a[j]);});
	sort(a + 1 , a + n + 1);
	for(int i = 2 ; i <= n ; i ++)
		st.insert(a[i] - a[i - 1]);
	if(st.size() > 3)dokme(-1);
	for(int i = 0 ; i < 3 ; i ++)cnt[i].first = inf;
	for(int i = 2 ; i <= n ; i ++){
		ll val = a[i] - a[i - 1];
		bool ok = 1;
		for(int j = 0 ; j < 3 ; j ++){
			if(val == cnt[j].first){
				cnt[j].second++;
				ok = 0;
			}
		}
		if(ok){
			for(int j = 0 ; j < 3 ; j ++)
				if(cnt[j].first == inf){
					cnt[j].first = val;
					cnt[j].second ++;
					break;
				}
		}
	}
	for(int i = 1 ; i <= n ; i ++)ord[srt[i]] = i;
	for(int i = 1 ; i <= n ; i ++){
		if(chk(i))
			dokme(srt[i]);
	}
	cout << -1;
	return(0);
}
