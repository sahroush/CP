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

string s , t;
int q;

vector < pii > comp(string s){
	vector < pii > com;
	com.pb({s[0] , 1});
	for(int i = 1 ; i < (int)s.size() ; i ++){
		if(s[i] != com.back().first)com.pb({s[i] , 0});
		com.back().second++;
	}
	return(com);
}

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> s >> t;
		auto a = comp(s) , b = comp(t);
		if(a.size() != b.size()){cout << "NO" << endl;continue;}
		bool ok = 1;
		for(int i = 0 ; i < (int) a.size()  ; i ++){
			if(a[i].first != b[i].first)ok = 0;
			if(a[i].second > b[i].second)ok = 0;
		}
		cout << ((ok) ? "YES" : "NO")  << endl;
	}

	return(0);
}
