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

const ll maxn  = 2e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
int cnt[maxn+1];

int32_t main(){
    migmig;
	cin >> n >> k;
	for(int i = 0 ; i < n ; i ++){
		int h;
		cin >> h;
		cnt[h]++;
	}
	int ans = 0;
	int cur = 0;
	for(int i = maxn ; i >= 0 ; i --){
		if(!cnt[i])continue;
		if(cnt[i] == n)dokme(ans + (cur > 0));
		if(cur + cnt[i] > k)
			cur = 0 , ans ++ ;
		cur += cnt[i];
		cnt[i - 1] += cnt[i];
	}
    return(0);
}
