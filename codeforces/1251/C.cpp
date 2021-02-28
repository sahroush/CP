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

#define f(i) (s[i] - '0')

int q;
string s;

vector < int > v[2];

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> s;
		int n = s.size();
		v[0].clear() , v[1].clear();
		for(int i = 0 ; i < n ; i ++)
			v[f(i)%2].pb(f(i));
		int p1 = 0 , p2 = 0;
		for(int i = 0 ; i < n ; i ++){
			if(p1 < (int)v[0].size() and p2 < (int)v[1].size()){
				if(v[0][p1] < v[1][p2])cout << v[0][p1++];
				else cout << v[1][p2++];
			}
			else if(p1 < (int)v[0].size()){
				cout << v[0][p1++];
			}
			else
				cout << v[1][p2++];
		}
		cout << endl;
	}
	return(0);
}
