#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);
const ll K = 3;

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1LL){res=(a*res)%md;}a=(a*a)%md;b>>=1LL;}return(res);}

struct Mat{
    ll m[K][K];
    Mat(ll diag = -1){
        ms(m , 0);
        if(diag==0)for(int i = 0 ; i < K ; i ++)m[i][i] = 1;
        if(diag>0)for(int i = 0 ; i < diag ; i ++)m[i][i+1]=1;
    }
    Mat operator* (const Mat &b) const{
        Mat c = Mat();
        for(int i = 0 ; i < K ; i ++)
            for(int k = 0 ; k < K ; k ++)
                for(int j = 0 ; j < K ; j ++)
                    c.m[i][j] = (ll(c.m[i][j]) + ll(m[i][k]) * b.m[k][j])%(mod-1);
        return(c);
    }
};
Mat pw(Mat a, ll b){Mat res(0);while(b){if(b&1LL){res=(a*res);}a=(a*a);b>>=1LL;}return(res);}

Mat m(-1);
ll n , f1 , f2 , f3 , c;

int main(){
    migmig
    m.m[0][1] = 1;
    m.m[1][2] = 1;
    m.m[2][0] = m.m[2][1] = m.m[2][2] = 1;
    cin >> n >> f1 >> f2 >> f3 >> c;
    m = pw(m , n-3);
    f1 = (f1 * c)%mod;
    f2 = (f2 * pw(c , 2))%mod;
    f3 = (f3  * pw(c , 3))%mod;
    ll ans =( pw(f1 , m.m[2][0]) % mod * pw(f2 , m.m[2][1]) %mod * pw(f3 , m.m[2][2]) %mod)%mod;
    cout << (ans * pw(pw(c , n), mod - 2))%mod;
    return(0);
}