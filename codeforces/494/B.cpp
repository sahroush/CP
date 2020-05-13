#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s , t;
vector < int > f;
int n , m;
ll dp[maxn][3];
ll ans = 0;

vector < int > kmp (string s){
	int n = s.size();
	vector < int > f(n);
	for(int i = 1 ; i < n ; i ++){
		int j = f[i - 1];
		while(j and s[i]!=s[j])
			j = f[j-1];
		j+=(s[i] == s[j]) , f[i] = j;
	}
	return(f);
}


int main(){
    migmig
    cin >> s >> t;
    f = kmp(t + "$" + s);
    n = s.size() , m = t.size();
    for(int i = 1 ; i <= n ; i ++){ 
		if(f[m + i]==m){
			dp[i][0] = (dp[i - m][2] + i - m + 1)%mod;
			dp[i][1] = (dp[i][0] + dp[i-1][1])%mod;
			dp[i][2] = (dp[i-1][2] + dp[i][1])%mod;
		}
		else{
			dp[i][0] = dp[i-1][0];
			dp[i][1] = (dp[i][0] + dp[i-1][1])%mod;
			dp[i][2] = (dp[i-1][2] + dp[i][1])%mod; 
		} 
	}
    for(int i = 1 ; i <= n ; i ++)
		ans = (ans + dp[i][0])%mod;
    cout << ans;
    return(0);
}