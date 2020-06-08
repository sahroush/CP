#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);
const ll K = 110;

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct Mat{
    int m[K][K];
    Mat(int diag = -1){
        ms(m , 0);
        if(diag==0)for(int i = 0 ; i < K ; i ++)m[i][i] = 1;
        if(diag>0)for(int i = 0 ; i < diag ; i ++)m[i][i+1]=1;
    }
    Mat operator* (const Mat &b) const{
        Mat c = Mat();
        for(int i = 0 ; i < K ; i ++)
            for(int k = 0 ; k < K ; k ++)
                for(int j = 0 ; j < K ; j ++)
                    c.m[i][j] = (ll(c.m[i][j]) + ll(m[i][k]) * b.m[k][j])%mod;
        return(c);
    }
};
Mat pw(Mat a, ll b){Mat res(0);while(b){if(b&1){res=(a*res);}a=(a*a);b>>=1;}return(res);}

int dp[K];
ll n;
int t;

int main(){
    migmig
    cin >> n >> t;
    dp[0] = 1;
    for(int i = 1 ; i <= t ; i ++)
        dp[i] = (dp[i-1] +  ((i-t>=0)?dp[i-t]:0))%mod;
    if(n <= t)
        dokme(dp[n]);
    Mat m(t);
    m.m[t-1][t-1] = m.m[t-1][0] = 1;
    m = pw(m , n-t+1);
    ll ans = 0;
    for(int i = 0 ; i < t ; i ++)
        ans = (ans + ll(dp[i]) * m.m[t-1][i]%mod)%mod;
    cout << ans;
    return(0);
}