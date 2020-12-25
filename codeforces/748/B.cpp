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

string s , t;

int mat[40];

int32_t main(){
    migmig;
	cin >> s >> t;
	int n = s.size();
	for(int i = 0 ; i < n ; i ++){
		int a = s[i] - 'a' + 1;
		int b = t[i] - 'a' + 1;
		if(mat[a]){
			if(mat[a]!=b)dokme(-1);
		}
		if(mat[b]){
			if(mat[b]!=a)dokme(-1);
		}
		mat[a] = b;
		mat[b] = a;
	}
	int cnt = 0;
	vector < pair < char , char > > A;
	for(int i = 1 ; i <= 30 ; i ++){
		if(!mat[i])continue;
		if(mat[i] == i)continue;
		cnt++;
		mat[mat[i]] = 0;
		A.pb({char('a' + i - 1) ,char('a' + mat[i] - 1)});
	}
	cout << cnt << endl;
	for(auto [f , s] : A)
		cout << f << ' ' << s << endl;


    return(0);
}
