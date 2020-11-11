/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
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

int n;
string s[maxn];

void fuck(int x , int y){
	if(s[x][y] == '#')return;
	if(s[x][y-1] == '#')return;
	if(s[x][y+1] == '#')return;
	if(s[x+1][y] == '#')return;
	if(s[x-1][y] == '#')return;
	s[x][y] = s[x+1][y] = s[x - 1][y] = s[x][y+1] = s[x][y - 1] = '#';
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 0 ; i < n ; i ++)	
		cin >> s[i];
	for(int i = 1 ; i < n - 1 ; i ++)
		for(int j = 1 ; j < n-1 ; j ++)
			if(s[i][j] == '.')fuck(i , j);
	for(int i = 0 ; i < n ; i ++)
		for(int j =0 ; j < n ; j ++)
			if(s[i][j] == '.')dokme("NO");
	dokme("YES");
    return(0);
}
