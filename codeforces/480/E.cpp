
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

const ll maxn = 2017;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , k ;
int x[maxn] , y[maxn];
string s[maxn];

int ans = 0;

int up[maxn][maxn] , down[maxn][maxn];

deque < int > u , d;

bool chk(int x , int k){
	u.clear();
	d.clear();
	if(k > m)return(0);
	for(int i = 1 ; i < k ; i ++){
		while(u.size() and up[x][i] <= up[x][u.back()])
			u.pop_back();
		u.pb(i);
		while(d.size() and down[x][i] <= down[x][d.back()])
			d.pop_back();
		d.pb(i);
	}
	for(int i = k ; i <= m ; i ++){
		while(u.size() and up[x][i] <= up[x][u.back()])
			u.pop_back();
		u.pb(i);
		while(d.size() and down[x][i] <= down[x][d.back()])
			d.pop_back();
		d.pb(i);
		if(up[x][u.front()] + down[x][d.front()] > k)return(1);
		if(d.front() == i - k + 1)d.pop_front();
		if(u.front() == i - k + 1)u.pop_front();
	}
	return(0);
}

int solve(int i){
	int l = 0 , r = n+1;
	while(r - l > 1){
		int mid = (l + r)/2;
		if(chk(i , mid))
			l = mid;
		else
			r = mid;
	}
	return(l);
}

void solve(){
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			if(s[i][j]!='X')	
				up[i][j] = up[i - 1][j] + 1;
	for(int i = n ; i ; i --)
		for(int j = 1 ; j <= m ; j ++)
			if(s[i][j] != 'X')
				down[i][j] = down[i+1][j] + 1;
	for(int i = 1 ; i <= n ; i ++)
		ans = max(ans , solve(i));
}

vector < int > Ans;

int32_t main(){
    migmig;
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i ++){
		cin >> s[i];
		s[i] = "7" + s[i];
	}
	for(int i = 1 ; i <= k ; i ++)
		cin >> x[i] >> y[i] , s[x[i]][y[i]] = 'X';
	solve();
	for(int i = k ; i ; i --){
		s[x[i]][y[i]] = '.';
		for(int j = 1 ; j <= n ; j ++)
			if(s[j][y[i]]!='X')	
				up[j][y[i]] = up[j - 1][y[i]] + 1;
		for(int j = n ; j ; j --)
			if(s[j][y[i]] != 'X')
				down[j][y[i]] = down[j+1][y[i]] + 1;
		Ans.pb(ans);
		ans = max(ans , solve(x[i]));
	}
	reverse(Ans.begin() , Ans.end());
	for(int x : Ans)cout << x << endl;
    return(0);
}
