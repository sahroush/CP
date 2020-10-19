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

const ll maxn  = 77799;
const ll mod =777777777; // mage marizi ?!
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
bool good[4][4];
ll seg[4*maxn][4][4];
ll cur[4][4];

void calc(int par , int L , int R){
    ms(seg[par] , 0);
    for(int r = 1 ; r <= 3 ; r ++)
        for(int l = 1 ; l <= 3 ; l ++)
            if(good[r][l])
                for(int i = 1 ; i <= 3 ; i ++)
                    for(int j = 1 ; j <= 3 ; j ++)
                        seg[par][i][j] = (seg[par][i][j] + (seg[L][i][r] * seg[R][l][j])%mod)%mod;
}

void build(int v = 1 , int l = 1 , int r = n+1){
    if(r - l == 1){
        for(int i = 1 ; i <= 3 ; i ++)
            seg[v][i][i] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2*v , l , mid);
    build(2*v+1 , mid , r);
    calc(v , 2*v , 2*v+1);
}

void update(int pos , int x , int v = 1 , int l = 1 , int r = n+1){
    if(r - l == 1){
        ms(seg[v] , 0);
        if(x){
            seg[v][x][x] = 1;
        }
        else{
            for(int i = 1 ; i <= 3 ; i ++)
                seg[v][i][i] = 1;
        }
        return;
    }
    int mid = (l + r)/2;
    if(pos < mid)
        update(pos , x , 2*v , l , mid);
    else
        update(pos , x , 2*v + 1 , mid , r);
    calc(v , 2*v , 2*v+1);
}

ll solve(){
    ll ans = 0;
    for(int i = 1 ; i <= 3 ; i ++)
        for(int j = 1 ; j <= 3 ; j ++)
            ans = (ans + seg[1][i][j])%mod;
    return(ans);
}

int32_t main(){
    migmig;
    cin >> n >> q;
    for(int i = 1 ; i <= 3 ; i ++)
        for(int j = 1 ; j <= 3 ; j ++ )
            cin >> good[i][j];
    build();
    while(q -- ){
        int pos;
        int x;
        cin >> pos >> x;
        update(pos , x);
        cout << solve() << endl;
    }
    return(0);
}