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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
bool mark[maxn];
int b[maxn] , sz = 0;

int32_t main(){
	migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i ++){
		if(!mark[a[i]]){
			b[++sz] = a[i];
			for(int j = a[i] ; j < maxn ; j += a[i])
				mark[j] = 1;
		}
	}
	int cnt = 0;
	int ans = 8;
	while(cnt < 1e7){
		cnt++;
		int gc = b[rng()%sz + 1];
		if(gc == 1)ans = 1;
		for(int i = 2 ; i < ans ; i ++){
			gc = __gcd(gc , b[rng()%sz+1]);
			if(gc == 1)ans = i;
		}
	}
	cout << ((ans == 8) ? -1 : ans);
	return(0);
}
