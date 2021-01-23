//*
//#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 27;
const int maxa = 50010;
const int maxs = maxn * maxa * 2;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn*2];
bitset < maxs > bit[maxn*2][maxn];
vector < int > ans[2];

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 0 ; i < 2*n ; i ++)
		cin >> a[i];
	sort(a , a + 2*n);
	reverse(a , a + 2*n);
	bit[0][0][0] = 1;
	for(int i = 0 ; i < 2*n - 2 ; i ++)
		for(int j = 0 ; j <= min(n - 2 , i) ; j ++)
			bit[i + 1][j + 1] |= bit[i][j] << a[i],
			bit[i + 1][j] |= bit[i][j];
	int sum = 0 , mn = 0;
	for(int i = 0 ; i < 2*n - 2; i ++)sum += a[i];
	auto bs = bit[n * 2 - 2][n - 1];
	for(int i = bs._Find_first() ; i < maxs ; i = bs._Find_next(i))
		if(max(i , sum - i) < max(mn , sum - mn))mn = i;
	for(int i = 2 * n - 3 , j = n - 1 ; i >= 0 ; i --)
		if(j and mn >= a[i] and bit[i][j - 1][mn - a[i]])
			ans[0].pb(a[i]) , j -- , mn -= a[i];
		else
			ans[1].pb(a[i]);
	cout << a[2 * n - 1] << ' ';
	for(int i : ans[0])cout << i << ' ';
	cout << endl;
	reverse(ans[1].begin() , ans[1].end());
	for(int i : ans[1])cout << i << ' ';
	cout << a[2*n - 2];
    return(0);
}
