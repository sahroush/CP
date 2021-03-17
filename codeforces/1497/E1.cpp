///*
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

const int maxn = 1e7+2;
const ll mod = 15487237;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , k;
int a[200100];
ll hsh[maxn];
bool bad[maxn];
int fuck[maxn];
set < int > st;


int32_t main(){
	migmig;
	cin >> q;
	for(int i = 1 ; i < maxn ; i ++)hsh[i] = 1;
	for(int i = 2 ; i < maxn ; i ++)if(!bad[i]){
		for(int j = i ; j < maxn ; j += i){
			bad[j] = 1;
		}
		ll x = i;
		int inv = pw(i , mod - 2);
		while(x < maxn){
			for(int j = 0 ; j < maxn ; j += x){
				if(fuck[j] == i)hsh[j] = (hsh[j] * inv)%mod , fuck[j] = 0;
				else hsh[j] = (hsh[j] * i)%mod , fuck[j] = i;
			}
			x = x * i;
		}
	}
	hsh[1] = 1;
	while(q --){
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++){
			if(st.count(hsh[a[i]])){
				ans ++;
				st.clear();
			}
			st.insert(hsh[a[i]]);
		}
		if(st.size()){
			ans ++ ;
			st.clear();
		}
		cout << ans << endl;
	}
	return(0);
}
