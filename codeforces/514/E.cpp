#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);
const ll K = 108;

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct Mat{
    int m[K][K];
    Mat(int diag = 0){
        ms(m , 0);
        if(diag==1)for(int i = 0 ; i < K ; i ++)m[i][i] = 1;
        if(diag==2)for(int i = 0 ; i < 99 ; i ++)m[i][i+1]=1;
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
Mat pw(Mat a, ll b){Mat res(1);while(b){if(b&1){res=(a*res);}a=(a*a);b>>=1;}return(res);}

int n , x;
Mat m(2);
int cnt[K];
int dp[K];

int main(){
    migmig
    cin >> n >> x;
    while(n -- ){
        int d;
        cin >> d;
        cnt[d]++;
    }
    dp[0] = 1;
    for(int i = 1 ; i <= 100 ; i ++)
        for(int j = 1 ; j <= i ; j ++)
            dp[i] = (dp[i] + ll(cnt[j]) * ll(dp[i-j])%mod)%mod;
    for(int i = 0 ; i <= 100 ; i ++)dp[101] = (dp[101] + dp[i])%mod;
    if(x <= 100){
        int ans = 0;
        for(int i = 0 ; i <= x ; i ++)ans = (ans + dp[i])%mod;
        dokme(ans);
    }
    x-=100;
    for(int i = 0 ; i < 100 ; i ++){
        m.m[99][i] = m.m[100][i] = cnt[100-i];
    }
    m.m[100][100] = 1;
    m = pw(m , x);
    int ans = 0;
    for(int i = 0 ; i <= 100 ; i ++){
        ans = (ans + ll(dp[i+1]) * ll(m.m[100][i]))%mod;
    }
    cout << ans;
    return(0);
}