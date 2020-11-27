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

const ll maxn  = 1e5 + 10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int cnt[maxn];
int sum[maxn];
int mark[maxn];
int i;

void add(int x , int d = 0){
	if(mark[x] == i)return;
	mark[x] = i;
	if(x > 1)add(x/2 , d+1);
	if(2*x < maxn) add(2*x , d+1);
	cnt[x]++;
	sum[x] += d;
}

int32_t main(){
    migmig; 
	cin >> n;
	for(i = 1 ; i <= n ; i ++){
		int x;
		cin >>x;
		add(x);
	}
	int ans = 1e9;
	for(int i = 0 ; i < maxn ; i ++)
		if(cnt[i] == n)ans = min(ans , sum[i]);
	cout << ans;
    return(0);
}
