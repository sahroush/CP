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
string s;

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n >> s;
		int prv = -1;
		string ans = "";
		for(int i = 0 ; i < n ; i ++){
			if(s[i] == '1'){
				if(prv != 2)
					ans += '1', prv = 2;
				else
					ans += '0', prv = 1;
			}
			else{
				if(prv != 1)
					ans += '1' , prv = 1;
				else
					ans += '0', prv = 0;
			}
		}
		cout << ans << endl;
	}




    return(0);
}
