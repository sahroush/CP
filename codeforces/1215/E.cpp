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

int a[maxn] , cnt[maxn] , n;
ll cost[40][40];
ll dp[maxn];

int main(){
    migmig
    ms(dp , 63);
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
		cin >> a[i];
		a[i]--;
		for(int j = 0 ; j < 20 ; j ++ ){
			cost[a[i]][j]+=cnt[j];
		}
		cnt[a[i]]++;
	}
    dp[0] = 0;
    for(int i = 0 ; i < (1 << 20) ; i ++){
		for(int j = 0 ; j < 20 ;  j ++){
			if(i&(1 << j))continue;
			ll sum = 0;
			for(int k = 0 ; k < 20 ; k ++ ){
				if(i&(1 << k))sum+=cost[j][k];
			}
			dp[i|(1 << j)] = min(dp[i|(1 << j)] , dp[i] + sum);
		}
	}
	cout << dp[(1 << 20) - 1];
    return(0);
}

