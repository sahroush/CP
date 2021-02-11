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

int q , n;
int a[maxn];

int f(int x){
	if(x<= 1 or x >= n)return(0);
	return((a[x] > a[x - 1] and a[x] > a[x + 1]) or (a[x] < a[x - 1] and a[x] < a[x + 1]));
}

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		int sum = 0;
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		for(int i = 1 ; i <= n ; i ++)
			sum += f(i); 
		ans = sum;
		sum -= f(1) + f(2);
		int org = a[1];
		a[1] = a[2];
		ans = min(ans , sum + f(2) + f(1));
		a[1] = org;
		sum += f(1) + f(2);
		sum -= f(n) + f(n-1);
		org = a[n];
		a[n] = a[n - 1];
		ans = min(ans , sum + f(n) + f(n-1));
		a[n] = org;
		sum += f(n) + f(n-1);
		for(int i = 2 ; i < n ; i ++){
			org = a[i];
			sum -= f(i) + f(i - 1) + f(i + 1);
			
			a[i] = a[i - 1];
			ans = min(ans , sum + f(i) + f(i - 1) + f(i + 1));
			a[i] = a[i + 1];
			ans = min(ans , sum + f(i) + f(i - 1) + f(i + 1));
			
			a[i] = org;
			sum += f(i) + f(i - 1) + f(i + 1);
		}
		cout << ans << endl;
	}




    return(0);
}
