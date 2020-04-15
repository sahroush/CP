#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5+2;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , p , k;
struct per{
	ll a , s[7];
}pr[maxn];
ll dp[maxn][(1 << 7)];

bool cmp(per i , per j){
    return(i.a > j.a);
}

int main(){
    migmig
    cin >> n >> p >> k;
    ms(dp, -1);
    dp[0][0] = 0;
    for(int i = 1 ; i <= n ; i ++ )
		cin >> pr[i].a;
    for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j < p ; j ++)
			cin >> pr[i].s[j];
    sort(pr +1 , pr + n+1 ,cmp);
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 0 ; j < (1 << p) ; j ++){
            if((i - 1)- __builtin_popcount(j) < k ){
				if(dp[i-1][j]!=-1){
					dp[i][j] = dp[i-1][j]+pr[i].a;
                }
            }
			else{
				if(dp[i-1][j]!=-1){
					dp[i][j] = dp[i-1][j];
                }
            }
			for(int k = 0 ; k < p ; k ++){
				if((j&(1 << k)) and dp[i-1][j - (1 << k)]!=-1){
					dp[i][j] = max(dp[i][j] , pr[i].s[k] + dp[i-1][j-(1 << k)]);
                }
            }
		}
    }
    cout << dp[n][(1 << p)-1];
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
