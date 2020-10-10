/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int dp[maxn];
int r , n;
int x[maxn] , y[maxn] , t[maxn];
bool reach[maxn];
vector < int > vec;


int d(int i , int j){
    return(abs(x[i] - x[j]) + abs(y[i] - y[j]));
}

int32_t main(){
    migmig
    cin >> r >> n;
    x[0] = y[0] = 1;
    reach[0] = 1;
    int mx = 0;
    vec.pb(0);
    for(int i = 1 ; i <= n ; i ++){
        cin >> t[i] >> x[i] >> y[i];
        if(d( i , 0) <= t[i]) vec.pb(i);
    }
    int mxdp = 0;
    for(int i = 1 ; i < vec.size() ; i ++){
        dp[i] = 1;
        for(int j = max(0LL , i - 1100) ; j < i ; j ++){
            if(d(vec[i] , vec[j]) + t[vec[j]] <= t[vec[i]])
                dp[i] = max(dp[i] , dp[j] + 1);
        }
        dp[i] = max(dp[i] , mxdp + 1);
        if(i >= 1100)mxdp = max(mxdp , dp[i-1100]);
        mx = max(mx , dp[i]);
    }
    cout << mx;
    return(0);
}