#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 600;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
int a[maxn] , b[maxn];
ll suma , sumb;
bool dp[600][600];
ll ans = 0;

int main(){
    migmig
    cin >> n >> k;
    for(int i = 1 ;i <= n ; i ++){
		cin >> a[i] >> b[i];
		suma+=a[i];
		sumb+=b[i];
	}
	dp[0][0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j < k  ; j ++){
			dp[i][j] |= dp[i - 1][((j - a[i] % k)+k)%k];
			for(int h = 0 ; h < min(k , a[i] + 1) ; h ++)
				if((a[i] - h)%k + b[i] >= k)
					dp[i][j]|=dp[i - 1][((j - h % k)+k)%k];
		}
	for(int i = 0 ; i < k ; i ++)
		if(dp[n][i])
			ans = max(ans , (suma + sumb - i)/k);
	cout << ans;
    return(0);
}

