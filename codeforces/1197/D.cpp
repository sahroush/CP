#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5+8;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , k , m , ans = 0;
ll a[maxn] , prt[maxn];
ll dp[maxn][20][3];

ll calc(int x){
	ll a , b;
	a = x/m;
	b = (x + 1)/m;
	if(x%m)a++;
	if((x + 1)%m)b++;
	return((b - a)*k);
}

ll solve(int pos = 1 , int c = 0 , int l = 0){
	c%=m;
	if(pos > n)return(0);
	if(dp[pos][c][l]!=-1)
		return(dp[pos][c][l]);
	if(l == 0){
		dp[pos][c][l] = solve(pos + 1 , 0 , 0);
		ll val = (a[pos] - calc(c)) + solve(pos + 1 , c + 1 , 1);
		dp[pos][c][l] = max(dp[pos][c][l] , val);
		return(dp[pos][c][l]);
	}
	if(l == 1){
		dp[pos][c][l] = solve(pos + 1 , 0 , 2);
		ll val = (a[pos] - calc(c)) + solve(pos + 1 , c + 1 , 1);
		dp[pos][c][l] = max(dp[pos][c][l] , val);
		return(dp[pos][c][l]);
	}
	dp[pos][c][l] = 0;
	return(0);
}

int main(){
    migmig
    cin >> n >> m >> k;
    for(int i = 1 ;i <= n ; i ++){
		cin >> a[i];
	}
    ms(dp , -1);
    cout << solve();
    return(0);
}

