#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int n;
int a[maxn];
int dp[6000][6000][2];

int solve(int pos , int l , bool f){
    if(l == 0){
        return(0);
    }
    if(pos <= 0 and l > 0){
        return(1e9);
    }
    if(dp[pos][l][f]!= -1){
        return(dp[pos][l][f]);
    }
    int ans = solve(pos-1 , l , 0);
    int cur = 0;
    if(f){
        cur = max(cur , a[pos+2]-a[pos]);
    }
    else{
        cur = max(cur, a[pos+1] - a[pos] + 1);
    }
    if(a[pos] > a[pos-1]){
        ans = min(ans , solve(pos - 2 ,l-1 , 0 ) + cur);
    }
    else{
        ans = min(ans , solve(pos-2 , l - 1 , 1) + max(0 , a[pos-1] - a[pos] + 1) + cur);
    }
    dp[pos][l][f] = ans;
    return(ans);
}

int main(){
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i];
    }
    ms(dp , -1);
    for(int i = 1 ; i <= (n+1)/2 ; i ++){
        cout << solve(n , i , 0) << ' ';
    }


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
