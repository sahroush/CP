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

const int maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int t[maxn] , g[maxn];

ll fact[30] , inv[30];

ll C(ll r , ll n){
	return((fact[n] * inv[r])%mod * inv[n-r])%mod;
}

int cnt[30][30][30];

int p3[30];

void calc(int n){
	for(int i = 0 ; i < p3[n] ; i ++){
		int a = 0 , b = 0 , c = 0;
		int x = i;
		int lst = -1;
		bool ok = 1;
		for(int k = n-1 ; k >= 0 ; k --){
			if(x >= (p3[k] << 1)){
				a++;
				x -= (p3[k] << 1);
				if(lst == 2){ok = 0;break;}
				lst = 2;
			}
			else if(x >= (p3[k])){
				b++;
				x -= (p3[k]);
				if(lst == 1){ok = 0;break;}
				lst = 1;
			}
			else{
				c++;
				if(lst == 0){ok = 0;break;}
				lst = 0;
			}
		}
		if(ok)cnt[a][b][c] ++;
	}
}

int32_t main(){
	migmig;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i ++)
		cin >> t[i] >> g[i] , g[i] --;
	fact[0] = inv[0] = 1;
	for(int i = 1 ; i < 30 ; i ++)
		fact[i] = (fact[i - 1] * i)%mod , inv[i] = pw(fact[i] , mod - 2);
	p3[0] = 1;
	for(int i = 1 ; i <= n ; i++)
		p3[i] = p3[i - 1] * 3;
	for(int i = 0 ; i <= n ; i ++)calc(i);
	ll ans = 0;
	for(int i = 0 ; i < (1 << n) ; i ++){
		int sum = 0;
		int cnt[] = {0 , 0 , 0};
		for(int j = 0 ; j < n ; j ++){
			if(i & (1 << j)){
				cnt[g[j]]++;
				sum += t[j];
			}
		}
		if(sum != m)continue;
		ll res = ::cnt[cnt[0]][cnt[1]][cnt[2]];
		res = (((res * fact[cnt[0]])%mod * fact[cnt[1]])%mod * fact[cnt[2]])%mod;
		ans = (ans + res)%mod;
	}
	cout << ans;
	return(0);
}
