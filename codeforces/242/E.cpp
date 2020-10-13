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

const ll maxn  = 1e5 + 10;
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

int n;
int a[maxn];
int seg[maxn*4][25];
int q;
int lazy[maxn*4][25];

void build(int x ,int v = 1,  int l = 1,  int r = n + 1){
    if(r - l == 1){
        if(a[l] & (1 << x))
            seg[v][x] = 1;
        return;
    }
    int mid = (l + r)/2;
    build(x , 2*v , l , mid);
    build(x , 2*v + 1 , mid , r );
    seg[v][x] = seg[2*v][x] + seg[2*v + 1][x];
}

void shift(int x , int v , int l , int r){
    if(!lazy[v][x])return;
    seg[v][x] = r - l - seg[v][x];
    lazy[v][x] = 0;
    if(r - l == 1)
        return;
    lazy[2*v][x]^=1;
    lazy[2*v+1][x]^=1;
}

void update(int x , int L, int R , int v = 1 , int l = 1 , int r = n + 1){
    shift(x , v , l , r);
    if(v == 1)R++;
    if(r <= L or R <= l)
        return;
    if(L <= l and r <= R){
        lazy[v][x] ^= 1;
        shift(x , v , l , r);
        return;
    }
    int mid = (l + r) / 2;
    update(x , L , R , 2*v , l , mid);
    update(x , L , R , 2*v + 1 , mid , r);
    seg[v][x] = seg[2*v][x] + seg[2*v + 1][x];
}

int query (int x , int L, int R , int v = 1 , int l = 1 , int r = n + 1){
    if(v == 1)R++;
    if(r <= L or R <= l)
        return(0);
    shift(x , v , l , r);
    if(L <= l and r <= R)
        return(seg[v][x]);
    int mid = (l + r) / 2;
    return(
    query(x , L , R , 2*v , l , mid) + 
    query(x , L , R , 2*v + 1 , mid , r));
}

int32_t main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 0 ; i < 20 ; i ++)
        build(i);
    cin >> q;
    while(q -- ){
        int t;
        int l , r;
        cin >> t >> l >> r;
        if(t == 1){
            int ans = 0;
            for(int i = 0 ; i < 20 ; i ++)
                ans += (1 << i) * query(i , l , r);
            cout << ans << endl;
        }
        else{
            int x;
            cin >> x;
            for(int i = 0 ; i < 20 ; i ++)
                if(x & (1 << i))
                    update(i , l , r);
        }
    }
    return(0);
}