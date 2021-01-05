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

const ll maxn = 1e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , q;
char c[maxn][20];
pii tar[maxn][20];

const int sq = 500;

void up(int x){
	for(int i = 0 ; i < m ; i ++)
		tar[x][i] = {-1 , -1};
	for(int i = 0 ; i < m ; i ++)
		if(c[x][i] == '<'){
			if(i)	
				tar[x][i] = tar[x][i - 1];
			else
				tar[x][i] = {x , i - 1};
		}
		else if(c[x][i] == '^'){
			if(x%sq == 0)
				tar[x][i] = {x - 1 , i};
			else
				tar[x][i] = tar[x - 1][i];
		}
	for(int i = m - 1 ; i >= 0 ; i --)
		if(c[x][i] == '>'){
			if(i < m - 1)
				tar[x][i] = tar[x][i+1];
			else
				tar[x][i] = {x , i + 1};
		}
}

pii get(int x , int y){
	if(tar[x][y].second == m)
		return(pii(tar[x][y].first + 1 , tar[x][y].second + 1));
	if(tar[x][y].first == -1 and tar[x][y].second == -1)	
		return(pii(-1 , -1));
	if(min(tar[x][y].first, tar[x][y].second) == -1)
		return(pii(tar[x][y].first + 1 , tar[x][y].second + 1));
	return(get(tar[x][y].first , tar[x][y].second));
}

int32_t main(){
    migmig;
	cin >> n >> m >> q;
	for(int i = 0 ; i < n ; i ++)
		cin >> c[i];
	for(int i = 0 ; i < n ; i ++)
		up(i);
	while(q -- ){
		char t;
		int x , y;
		cin >> t;
		cin >> x >> y;
		if(t == 'A'){
			pii res = get(x-1 , y-1);
			cout << res.first << ' ' << res.second << endl;
		}
		else{
			char s;
			cin >> s;
			c[--x][--y] = s;
			int l = x/sq;
			for(int i = l*sq ; i < (l + 1)*sq ; i ++)
				up(i);
		}
	}
    return(0);
}
