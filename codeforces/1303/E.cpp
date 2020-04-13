#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 600;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("stupid_rmq.in", "r+", stdin); freopen("stupid_rmq.out", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
string s , t;
int dp[500][500];

int memo(int i , int j , int lim){
    if(i == 0){
        return((j)?-100000:1);
    }
    if(dp[i][j]!=-1){
        return(dp[i][j]);
    }
    int cur = memo(i -1 , j , lim);
    int ans = max(-100000 , cur);
    if(cur!=-100000 and cur <= lim and s[i-1] == t[cur-1]){
        ans = max(ans, cur+1);
    }
    if(j > 0 and s[i-1] == t[j + lim-1]){
        ans = max(ans , memo(i - 1, j - 1 , lim));
    }
    dp[i][j] = ans;
    return(ans);
}

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> s >> t;
        int n = s.size() , m = t.size();
        bool oke = 0;
        for(int i = 1 ; i <= m ; i ++){
            ms(dp , -1);
            if(memo(n , m - i , i) == i+1){
                oke = 1;
                break;
            }
        }
        cout << (oke?"Yes":"No") << endl;
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
