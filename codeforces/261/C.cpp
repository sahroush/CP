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

const ll maxn  = 60;
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

ll n , t;
ll c[maxn][maxn];

int32_t main(){
    migmig
    cin >> n >> t;
    int ans = 0;
    if(t == 1)ans--;
    if(__builtin_popcountll(t) != 1)
        dokme(0);
    c[0][0] = 1;
    for(int i = 1 ; i < maxn ; i ++){
        c[i][0] = 1;
        for(int j = 1 ; j <= i ; j ++)
            c[i][j] = c[i - 1][j] + c[i-1][j-1];
    }
    t = __builtin_ctzll(t) + 1;
    n+=1;
    int cnt = 0;
    for(ll i = 50 ; i >= 0 ; i --){
        if(cnt > t)break;
        if(n & (1LL << i))
            ans += c[i][t - cnt],
            cnt ++ ;
    }
    if(__builtin_popcountll(n) == t)
        ans ++;
    cout << ans;
    return(0);
}