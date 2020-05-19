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

ll n , k;
ll dp[200][200][27];
ll pd[200][200];
string s;


int main(){
    migmig
    cin >> n >> k;
    cin >> s;
    for(int i = 0 ; i <= n; i ++)
		pd[i][0]++;
	s = "%" + s;
	for(int i = 1 ; i <= n;  i ++ )
		for(int j = 1 ; j <= i ; j ++){
			for(int k = 26 ; k >= 0 ; k --)
				if(s[i]== 'a'+k)
					dp[i][j][k] = pd[i - 1][j - 1];
				else
					dp[i][j][k] = dp[i - 1][j][k];
			pd[i][j] = pd[i-1][j] + pd[i-1][j-1] - dp[i-1][j][s[i] - 'a'];
		}
	ll ans = 0;
	for(int i = n ; i >= 0 ; i --){
		if(!k)break;
		ll boz = min(pd[n][i] , k);
		k-=boz;
		ans += boz*n - boz*i;
	}
    if(k)
		dokme(-1);
	cout << ans;
    
    
    return(0);
}