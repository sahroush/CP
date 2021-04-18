//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 510;
const ll mod = 998244353;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

vector < int > vec = {-1};
int n , m , inv[maxn];
int l[maxn] , r[maxn];
int dp[maxn][maxn*2];
int y = 1;

int C(int r , int n){
	int res = 1;
	for( ; r > 0 ; r -- , n --)
		res = (res * 1ll * inv[r])%mod * n % mod;
	return res;
}

bool in(int i , int j){
	return (l[i] <= vec[j] and vec[j+1] <= r[i]);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 0 ; i < maxn ; i ++)inv[i] = pw(i , mod - 2);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> l[i] >> r[i] , r[i]++ , vec.pb(l[i]) , vec.pb(r[i]) , y = (y * 1LL * (r[i] - l[i]))%mod;
	reverse(l + 1 , l + 1 + n) , reverse(r + 1 , r + n + 1);
	sort(vec.begin() , vec.end());
	vec.resize(unique(vec.begin() , vec.end()) - vec.begin());
	m = vec.size()-1;
	for(int i = 0 ; i < m ; i ++)dp[0][i] = 1;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j < m ; j ++){
			for(int k = 1 ; k <= i ; k ++){
				if(!in(i - k + 1 , j))break;
				dp[i][j] = (dp[i][j] + (dp[i-k][j-1] * 1ll * C(k , vec[j+1] - vec[j] + k - 1))%mod)%mod;
			}
			dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
		}
	}
	cout << (dp[n][m-1] * 1ll * pw(y , mod-2))%mod;
	return(0);
}
