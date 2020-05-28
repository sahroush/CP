#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
int b[maxn];
int dp[maxn][3];

bool add(int x){
	bool oke = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(a[i] == x)b[i]=x , oke = 1;
	return(oke);
}

int calc(int x){
	int mx = 0;
	dp[0][0] = dp[0][1] = dp[0][2] = -1e9;
	for(int i = 1 ; i <= n ; i ++){
		dp[i][0] = dp[i][1] = dp[i][2] = -1e9;
		if(b[i] == -40)continue;
		if(x == b[i]){
			dp[i][1] = 0;//
			dp[i][1] = max(dp[i][1] , dp[i-1][0]);//
		}
		dp[i][0] = 0;//
		dp[i][0] = max(dp[i][0] , dp[i-1][0] + b[i]);//
		dp[i][0] = max(dp[i][0] , b[i]);//
		dp[i][2] = max(dp[i][2] , dp[i-1][2]+b[i]);//
		dp[i][2] = max(dp[i][2] , dp[i][1]);//
		mx = max(mx , dp[i][2]);
	}
	return(mx);
}

int main(){
    migmig
    //khoda rahm kone XD
    cin >> n;
    for(int i = 1 ;i <= n ; i ++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		b[i] = -40;
    for(int i = -30 ; i <= 30 ; i ++){
		if(!add(i))continue;
		ans = max(ans , calc(i));
	}
    cout << ans << endl;
    return(0);
}