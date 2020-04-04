#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;//AmShZ
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);
}

int n , k;
string s;
bool dp[2000][5000];
pii par[2000][5000];

int main(){
    //migmig
    cin >> n >> k ;
    cin >> s;
    dp[0][1000]=1;
    s = "%"+s;
    for(int i = 1 ; i <= n ; i ++){
        for(int j= 1000-k+(int)(i!=n) ; j < k+1000+(int)(i==n) ; j ++){
            if(s[i] == '?'){
                if(dp[i-1][j]){
                    dp[i][j]=1;
                    par[i][j] = {i-1 , j};
                }
                else if(dp[i-1][j-1]){
                    dp[i][j]=1;
                    par[i][j] = {i-1 , j-1};
                }
                else if(dp[i-1][j+1]){
                    dp[i][j]=1;
                    par[i][j] = {i-1 , j+1};
                }
            }
            if(s[i] == 'D'){
                dp[i][j]|=dp[i-1][j];
                par[i][j] = {i-1 , j};
            }
            if(s[i] == 'W'){
                dp[i][j]|=dp[i-1][j-1];
                par[i][j] = {i-1 , j-1};
            }
            if(s[i] == 'L'){
                dp[i][j]|=dp[i-1][j+1];
                par[i][j] = {i-1 , j+1};
            }
        }
    }
    if(dp[n][k+1000] == 0 and dp[n][1000 - k] == 0){
        dokme("NO");
    }
    string ans = "";
    if(dp[n][1000+k]){
        pii cur = {n , k+1000};
        while(cur!=pii(0 , 1000)){
            if(cur.second - par[cur.first][cur.second].second == 0){
                ans+="D";
            }
            else if(cur.second - par[cur.first][cur.second].second == 1){
                ans+="W";
            }
            else{
                ans+="L";
            }
            cur = par[cur.first][cur.second];
        }
    }
    else{
        pii cur = {n , 1000-k};
        while(cur!=pii(0 , 1000)){
            if(cur.second - par[cur.first][cur.second].second == 0){
                ans+="D";
            }
            else if(cur.second - par[cur.first][cur.second].second ==1){
                ans+="W";
            }
            else{
                ans+="L";
            }
            cur = par[cur.first][cur.second];
        }
    }
    reverse(ans.begin() , ans.end());
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
