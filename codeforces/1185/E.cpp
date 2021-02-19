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

const int maxn = 2100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , m;
string s[maxn];

int a[maxn] , b[maxn] , c[maxn] , d[maxn];

string ans[maxn];

int solve(){
	int res = 0;
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < m ; j ++)
			if(s[i][j] != '.')res = max(res , s[i][j] - 'a' + 1);
	for(int i = 0 ; i < res ; i ++)
		a[i] = b[i] = 1e9 , c[i] = d[i] = 0;
	int nue = 0;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			if(s[i][j] == '.')continue;
			int x = s[i][j] - 'a';
			a[x] = min(a[x] , i);
			b[x] = min(b[x] , j);
			c[x] = max(c[x] , i);
			d[x] = max(d[x] , j);
			nue = max(nue , x);
		}
	}
	for(int i = 0 ; i < res ; i ++)
		if(a[i] == 1e9)
			a[i] = a[nue] , b[i] = b[nue] , c[i] = c[nue] , d[i] = d[nue];
	return(res);
}

void build(int res){
	for(int i = 0 ; i < n ; i ++){
		ans[i] = "";
		for(int j = 0 ; j < m ; j ++)ans[i] += '.';
	}
	for(int i = 0 ; i < res ; i ++){
		if(a[i] == c[i]){
			for(int j = b[i] ; j <= d[i] ; j ++)
				ans[a[i]][j] = char('a' + i);
		}
		else if(b[i] == d[i]){
			for(int j = a[i] ; j <= c[i] ; j ++)
				ans[j][b[i]] = char('a' + i);
		}
	}
}

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n >> m;
		for(int i = 0 ; i < n ; i ++)
			cin >> s[i];
		int res = solve();
		if(res != -1){
			build(res);
			bool ok = 1;
			for(int i = 0 ; i < n ; i ++)
				if(ans[i] != s[i])ok = 0;
			if(!ok){
				cout << "NO" << endl;
				continue;
			}
			cout << "YES" << endl;
			cout << res << endl;
			for(int i = 0 ; i < res ; i ++)
				cout << a[i]+1 << ' ' << b[i] + 1 << ' ' << c[i] + 1 << ' ' << d[i] + 1 << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return(0);
}
