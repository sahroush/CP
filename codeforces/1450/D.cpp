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

int n;
int a[maxn];
int q;
int b[maxn];

int solve(int k){
	deque < int > dq;
	for(int i = 1 ; i < k ; i ++){
		while(dq.size() and a[dq.back()] >= a[i])dq.pop_back();
		dq.pb(i);
	}
	for(int i = k ; i <= n ; i ++){
		while(dq.size() and a[dq.back()] >= a[i])dq.pop_back();
		dq.pb(i);
		while(dq.front() < i-k + 1)dq.pop_front();
		b[i-k+1] = a[dq.front()];
	}
	sort(b+1 , b + n - k + 1 + 1);
	for(int i = 1 ; i <= n - k + 1 ; i ++)
		if(b[i]!=i)return(0);
	return(1);
}

int32_t main(){
    migmig;
	cin >> q;
	while(q --){
		cin >> n;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i];
		}
		cout << solve(1);
		int l = 1 , r = n + 1;
		while(r - l > 1){
			int mid = (l + r) / 2;
			if(solve(mid))
				r = mid;
			else 
				l = mid;
		}
		for(int i = 2 ; i <= n ; i ++){
			if(i >= r)cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
    return(0);
}
