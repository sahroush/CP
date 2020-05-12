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

int q;
int n;
int a[maxn];
int dp[maxn];
vector <int> dv[maxn];

int main(){
    migmig
    cin >> q;
    for(int i = 1 ; i < 5e5+100; i ++){
		for(int j = i ; j < 5e5+100 ; j += i){
			dv[j].pb(i);
		}
	}
    while(q -- ){
		cin >> n;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i];
		}
		for(int i = 0 ; i <= n ; i ++)dp[i] = 1;
		dp[1] = 1;
		int ans = 1;
		for(int i = 2 ; i <= n ; i ++){
			for(int j : dv[i]){
				if(a[i] > a[j]){
					dp[i] = max(dp[i] , dp[j] + 1);
				}
			}
			ans = max(ans , dp[i]);
		}
		cout << ans << endl;
	}
    
    
    
    
    return(0);
}