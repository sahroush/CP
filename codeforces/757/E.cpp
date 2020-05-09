#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e6+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll dp[maxn][25];
vector < int > vec[maxn];
int n , r;
int q;

int main(){
    migmig
    for(int i = 2 ; i < maxn ; i ++){
		if(vec[i].empty()){
			for(int j = i ; j < maxn ; j += i){
				vec[j].pb(i);
			}
		}
	}
	for(int i = 0 ; i < maxn ; i ++){
		dp[i][0] = 1;
		if(i < 25){
			dp[0][i] = 2;
		}
	}
	dp[0][0] = 0;
	for(int i = 1 ; i < 24 ; i ++){
		for(int j = 1 ; j < maxn ; j ++){
			dp[j][i] = (dp[j - 1][i] + dp[j][i - 1])%mod;
		}
	}
	cin >> q;
    while (q -- ){
		cin >> r >> n;
		ll ans = 1;
		for(int i  : vec[n]){
			int cnt = 0;
			while(n%i == 0 ){
				cnt++;
				n/=i;
			}
			ans*=dp[r][cnt];
			ans%=mod;
		}
		cout << ans << endl;
	}
    
    
    return(0);
}