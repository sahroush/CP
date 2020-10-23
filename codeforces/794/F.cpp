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

const ll maxn  = 1e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
int a[maxn];
vector < ll > cur[maxn*4] , cnt[maxn*4] , boz , khar(10 , 0);
bool lazy[maxn*4];

void build(int v = 1 , int l = 1 , int r = n + 1){
    cur[v] = boz;
    cnt[v] = khar;
    if(r - l == 1){
        int pw = 1;
        while(a[l]){
            cnt[v][a[l]%10] = (cnt[v][a[l]%10] + pw);
            pw = (pw * 10);
            a[l]/=10;
        }
        return;
    }
    int mid = (l + r) / 2;
    build(2*v , l , mid);
    build(2*v + 1 , mid , r);
    for(int i = 0 ; i < 10 ; i ++)
        cnt[v][i] = (cnt[2*v][i] + cnt[2*v + 1][i]);
}

void fufu(int p , int v){
    for(int i = 0 ; i < 10 ; i ++)
        cur[v][i] = cur[p][cur[v][i]];
    lazy[v] = 1;
}

void shift(int v , int l , int r){
    if(!lazy[v])return;
    if(r - l > 1){
        fufu(v, 2*v);
        fufu(v , 2*v + 1);
    }
    vector < ll > vec(10 , 0);
    for(int i = 0 ; i < 10 ; i ++)
        vec[cur[v][i]] += cnt[v][i] , vec[cur[v][i]];
    cur[v] = boz;
    cnt[v] = vec;
    lazy[v] = 0;
}

void update(int L , int R , int x , int y , int v = 1 , int l = 1 , int r = n + 1){
    shift(v , l , r);
    if(r <= L or R <= l)
        return;
    if(L <= l and r <= R){
        cur[v][x] = y;
        lazy[v] = 1;
        shift(v , l , r);
        return;
    }
    int mid = (l + r)/2;
    update(L , R , x , y , 2*v , l , mid);
    update(L , R , x , y , 2*v + 1 , mid , r);
    for(int i = 0 ; i < 10 ; i ++)
        cnt[v][i] = (cnt[2*v][i] + cnt[2*v + 1][i]);
}

ll query(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
    shift(v , l , r);
    if(r <= L or R <= l)
        return(0);
    if(L <= l and r <= R){
        ll ans = 0;
        for(int i = 0 ; i < 10 ; i ++)
            ans = (ans + (cnt[v][i] * ll(i)));
        return(ans);
    }
    int mid = (l + r)/2;
    return(query(L , R , 2*v , l , mid) + 
     query(L , R , 2*v + 1 , mid , r));
}

int32_t main(){
    migmig;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 0 ; i < 10 ; i ++)
        boz.pb(i);
    build();
    while(q -- ){
        int t , l ,r;
        cin >> t >> l >> r;
        if(t == 1){
            int x , y;
            cin >> x >> y;
            if(x == y)continue;
            update(l , ++r , x , y);
        }
        if(t == 2){
            cout << query(l , ++r) << endl;
        }
    }
    return(0);
}