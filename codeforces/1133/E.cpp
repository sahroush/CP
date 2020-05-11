#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
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
int a[maxn];
int dp[6000][6000];

int main(){
    migmig
    cin >> n >> k;
    for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
    sort(a , a + n);
    if(k >= n)dokme(n);
	dp[n-1][1] = 1;
	for(int i = 1 ; i <= k ; i ++){
		for(int j = n-i ; j >= 0 ; j --){
			int r = upper_bound(a + j , a+n , a[j] + 5) - a;
			dp[j][i] = max(dp[j+1][i] , dp[r][i-1]+r-j);
			dp[j][i] = max(dp[j][i] , dp[j][i-1]);
		}
	}
	cout << min(dp[0][k],n);
    return(0);
}