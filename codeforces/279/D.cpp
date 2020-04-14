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
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("stupid_rmq.in", "r+", stdin); freopen("stupid_rmq.out", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[24];
int res[100][100];
map<int , int> pos;
bool dp[(1 << 23)][24];

int main(){
    migmig
    cin >> n;
    ms(res , -1);
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    dp[1][1] = 1;
    for(int i = 1; i < n; i ++){
        for(int j = 1 ; j < (1 << i) ; j ++){
            if(!dp[j][i]){
                continue;
            }
            bool oke = 0;
            for(int k = 1 ; k <= i ; k ++){
                if(j & (1 << (k - 1))){
                    if(pos[a[i+1] - a[k] == 0]){
                        continue;
                    }
                    if((j & (1 << (pos[a[i + 1] - a[k]]) - 1))){
                        oke = 1;
                        break;
                    }
                }
            }
            if(!oke){
                continue;
            }
            for(int k = 0 ; k < i ; k ++){
                if((j & (1 << (k)))){
                    dp[(j^(1 << (k)))|(1 << i)][i + 1] = 1;
                }
            }
            dp[j|(1 << i)][i+1] = 1;
        }
    }
    int ans = 1e9;
    for(int i = 1  ; i < (1 << n) ; i ++){
        if(dp[i][n]){
            ans = min(ans , __builtin_popcount(i) );
        }
    }
    if(ans == 1e9){
        dokme(-1)
    }
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
