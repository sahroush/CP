#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);
const ll K = 2;

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , x , y , p;

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
                    c.m[i][j] = (ll(c.m[i][j]) + ll(m[i][k]) * b.m[k][j])%p;
        return(c);
    }
};
Mat pw(Mat a, ll b){Mat res(0);while(b){if(b&1){res=(a*res);}a=(a*a);b>>=1;}return(res);}


ll sum = 0;
ll mx , mx2 , mn;

Mat m(-1);

int main(){
    migmig
    cin >> n >> x >> y >> p;
    for(int i = 0 ; i < n ; i ++){
        cin >> mx;
        sum = (sum+mx)%p;
        if(!i)mn=mx;
        if(i==n-2)mx2=mx;
    }
    m.m[0][0] = 1 , m.m[1][1] = 3 , m.m[1][0] = p-1;
    m=pw(m , x);
    sum = (sum * m.m[1][1]%p + (mx+mn)*m.m[1][0]%p)%p;
    ms(m.m , 0);
    m.m[1][1]=m.m[1][0]=m.m[0][1]=1;
    m = pw(m , x);
    mx = (mx * m.m[1][1] %p + mx2 * m.m[1][0] % p )%p;
    ms(m.m , 0);
    m.m[0][0] = 1 , m.m[1][1] = 3 , m.m[1][0] = p-1;
    m = pw(m , y);
    sum = (sum * m.m[1][1]%p + (mx+mn)*m.m[1][0]%p)%p;
    cout << sum;
    return(0);
}