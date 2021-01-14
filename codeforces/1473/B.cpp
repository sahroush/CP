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

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
string s , t;
int n , m;

bool chk(string &a){
	int x = a.size();
	if(x%m)return(0);
	for(int i = 0 ; i < x ; i ++)
		if(a[i] != t[i%m])return(0);
	return(1);
}

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> s >> t;
		n = s.size() , m = t.size();
		string a = "";
		bool ok = 0;
		for(int i = 0 ; i < 410 ; i ++){
			a = a + s;
			if(chk(a)){
				cout << a << endl;
				ok = 1;
				break;
			}
		}
		if(!ok)cout << -1 << endl;
	}
    return(0);
}
