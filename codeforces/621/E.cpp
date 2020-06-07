#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll K  = 105;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

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
            for(int j = 0 ; j < K ; j ++)
                for(int k = 0 ; k < K ; k ++)
                    c.m[i][j] = (ll(c.m[i][j]) + ll(m[i][k]) * b.m[k][j])%mod;
        return(c);
    }
};
Mat pw(Mat a, ll b){Mat res(0);while(b){if(b&1){res=(a*res);}a=(a*a);b>>=1;}return(res);}

int cnt[K];
int n , b , k , x;
Mat m(-1);

int main(){
    migmig
    cin >> n >> b >> k >> x;
    while(n--){
        int d;
        cin >> d;
        cnt[d%x]++;
    }
    for(int i = 0 ; i < x ; i ++)
        for(int j = 0 ; j < x ; j ++)
            m.m[i][(i * 10 + j)%x]+=cnt[j];
    m = pw(m , b);
    cout << m.m[0][k];
    return(0);
}