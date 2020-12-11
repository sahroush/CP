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
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int sq = 200;

int n , q;
int a[maxn];
int b[200 + 10][maxn];
int c[200 + 10][maxn];

int t[maxn] , x[maxn] , y[maxn];
vector < int > vec;

int comp(int x){
	return(lower_bound(vec.begin() , vec.end() , x) - vec.begin());
}

int l[maxn] , r[maxn];

int32_t main(){
    migmig;
	cin >> n;
	sq = min(200.0 , sqrt(n));
	vec.pb(-1);
	for(int i = 1 ; i <= n;  i ++)
		cin >> a[i] , vec.pb(a[i]);
	cin >> q;
	for(int i = 1 ; i <= q ; i ++)
		cin >> t[i] >> x[i] >> y[i];
	for(int i = 1; i <= q ; i ++)
		if(t[i] == 1)vec.pb(x[i]);
	sort(vec.begin() , vec.end());
	vec.resize(unique(vec.begin() , vec.end()) - vec.begin());
	for(int i = 1 ; i <= n ; i ++)
		a[i] = comp(a[i]);
	for(int i = 1 ; i <= q ; i ++)
		if(t[i] == 1)x[i] = comp(x[i]);
	int qs = n/sq;
	for(int i = 1 ; i <= sq ; i ++){
		l[i] = r[i - 1] + 1;
		r[i] = qs * i;
	}
	if(r[sq] < n){
		sq++;
		l[sq] = r[sq - 1] + 1;
		r[sq] = n;
	}
	for(int i = 1 ; i <= sq ; i ++){
		for(int j = 1 ; j < maxn ; j ++)
			b[i][j] = b[i-1][j];
		for(int j = 1 ; j <= n ; j ++)
			c[i][j] = c[i - 1][j];
		for(int j = l[i] ; j <= r[i] ; j ++ )
			b[i][a[j]]++ , c[i][b[i][a[j]]]++;
		
	}
	for(int i = 1 ; i <= q ; i ++){
		if(t[i] == 1){
			int val = x[i] , pos = y[i];
			int block;
			for(int i = 1 ; i <= sq ; i ++)
				if(l[i] <= pos and pos <= r[i])
					block = i;
			int prv = a[pos];
			a[pos] = val;
			for(int i = block ; i <= sq ; i ++){
				c[i][b[i][prv]]-- , b[i][prv]--;
				b[i][val]++ , c[i][b[i][val]]++;
			}
		}
		if(t[i] == 2){
			int x = ::x[i] , y = ::y[i];
			int block;
			for(int i = 1 ; i <= sq ; i ++)
				if(l[i] <= y and y <= r[i])
					block = i;
			block --;
			int ans = b[block][a[y]];
			for(int j = l[block+1] ; j <= y ; j ++)
				ans += (a[j] == a[y]); 
			if(x == 1){
				cout << vec[a[y]];
			}
			else if(x%2 == 0){
				cout << ans;
			}
			else{
				int cnt = c[block][ans];
				for(int j = l[block+1] ; j <= y ; j ++)
					cnt += (++b[block][a[j]] == ans);
				for(int j = l[block+1] ; j <= y ; j ++)
					b[block][a[j]]--;
				cout << cnt;
			}
			cout << endl;
		}
	}
	return(0);
}
