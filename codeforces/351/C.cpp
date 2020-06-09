#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);
const ll K = 50;

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct Mat{
    ll m[K][K];
    Mat(int diag = -1){
        for(int i =0 ; i < K ; i ++)
            for(int j = 0 ; j < K ; j ++)
                m[i][j]=5e18;
    }
    Mat operator* (const Mat &b) const{
        Mat c = Mat(-1);
        for(int i = 0 ; i < K ; i ++)
            for(int k = 0 ; k < K ; k ++)
                for(int j = 0 ; j < K ; j ++)
                    c.m[i][j] = min(c.m[i][j], m[i][k] + b.m[k][j]);
        return(c);
    }
};
Mat pw(Mat a, ll b){Mat res=a;while(b){if(b&1){res=(a*res);}a=(a*a);b>>=1;}return(res);}

ll n , k;
ll a[K] , b[K];
Mat m(-1);
ll dp[K][K];

int main(){
    migmig
    cin >> n >> k;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i ++)
        cin >> b[i];
    for(int i = 0 ; i < K ; i ++){
        for(int j = 0 ; j <= n ; j ++)
            for(int h = 0 ; h < K ; h ++)
                dp[j][h] = 1e9;
        dp[0][i] = 0;
        for(int j = 0 ; j < n ; j ++)
            for(int h = 0 ; h < K ; h ++){
                if(h < 2*n-1)
                    dp[j+1][h+1]=min(dp[j+1][h+1], dp[j][h] + a[j]);
                if(h)
                    dp[j+1][h-1]=min(dp[j+1][h-1], dp[j][h] + b[j]);
            }
        for(int j = 0 ; j < K ; j ++)
            m.m[i][j] = dp[n][j];
    }
    m = pw(m , k-1);
    cout << m.m[0][0];
    return(0);
}