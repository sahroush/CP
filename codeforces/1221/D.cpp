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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , q , a[maxn] , b[maxn];
ll dp[maxn][5];

int main(){
    migmig
    cin >> q;
    while(q -- ){
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i] >> b[i];
		a[0] = -5;
		a[n+1] = -5;
		for(int i = 1 ; i <= n ; i ++){
			dp[i][0] = 2e18;
			if(a[i] != a[i-1]){
				dp[i][0] = dp[i-1][0];
			}
			if(a[i] != a[i-1]+1){
				dp[i][0] = min(dp[i][0] , dp[i-1][1]);
			}
			if(a[i] != a[i-1]+2){
				dp[i][0] = min(dp[i][0] , dp[i-1][2]);
			}
			dp[i][1] = 2e18;
			if(a[i]+1 != a[i-1]){
				dp[i][1] = dp[i-1][0]+b[i];
			}
			if(a[i]+1 != a[i-1]+1){
				dp[i][1] = min(dp[i][1] , dp[i-1][1]+b[i]);
			}
			if(a[i]+1 != a[i-1]+2){
				dp[i][1] = min(dp[i][1] , dp[i-1][2]+b[i]);
			}
			dp[i][2] = 2e18;
			if(a[i]+2 != a[i-1]){
				dp[i][2] = dp[i-1][0]+b[i]*2;
			}
			if(a[i]+2 != a[i-1]+1){
				dp[i][2] = min(dp[i][2] , dp[i-1][1]+b[i]*2);
			}
			if(a[i]+2 != a[i-1]+2){
				dp[i][2] = min(dp[i][2] , dp[i-1][2]+b[i]*2);
			}
		}
		cout << min(dp[n][0] , min(dp[n][1] , dp[n][2])) << endl;
	}
    
    
    
    
    return(0);
}