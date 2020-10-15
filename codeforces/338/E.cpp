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

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , h;
int b[maxn] , a[maxn];
int boz[maxn];

struct segment{
    #define lc(v) v << 1
    #define rc(v) lc(v)|1
    int maxn;
    vector < int > seg;
    vector < int > lazy;
    segment(int n):
        maxn(n + 100),
        seg(4 * maxn) , lazy(4 * maxn){}
    void build(int (&a)[::maxn] , int v = 1 , int l = 1 , int r = 0){
        if(r == 0)r = maxn;
        if(r - l == 1){
            seg[v] = a[l];
            return;
        }
        int mid = (l + r)/2;
        build(a , lc(v) , l , mid);
        build(a , rc(v) , mid , r);
        seg[v] = min(seg[lc(v)] , seg[rc(v)]);
    }
    void shift(int v , int l , int r){
        if(r - l > 1)
            lazy[lc(v)] += lazy[v],
            lazy[rc(v)] += lazy[v];
        seg[v] += lazy[v];
        lazy[v] = 0;
    }
    void update(int x , int L , int R , int v = 1 , int l = 1 , int r = 0){
        if(r == 0)r = maxn;
        shift(v , l , r);
        if(r <= L or R <= l)    
            return;
        if(L <= l and r <= R){
            lazy[v] += x;
            shift(v , l , r);
            return;
        }
        int mid = (l + r) / 2;
        update(x , L , R , lc(v) , l , mid);
        update(x , L , R , rc(v) , mid , r);
        seg[v] = min(seg[lc(v)] , seg[rc(v)]);
    }
    int query(int L , int R , int v = 1 , int l = 1 , int r = 0){
        if(r == 0)r = maxn;
        shift(v , l , r);
        if(r <= L or R <= l)    
            return(0);
        if(L <= l and r <= R){
            return(seg[v]);
        }
        int mid = (l + r) / 2;
        return(min(query(L , R , lc(v) , l , mid),
         query(L , R , rc(v) , mid , r)));
    }
};

int32_t main(){
    migmig
    cin >> n >> m >> h;
    for(int i = 1 ; i <= m ; i ++)  
        cin >> b[i];
    for(int i = 1 ; i <= n ; i ++)  
        cin >> a[i] , a[i] = h - a[i];
    // b[i] >= a[i]
    sort(b+1 , b + m + 1);
    b[m + 1] = 1e9 + 7;
    segment seg(m);
    for(int i = 1 , j = m ; i <= m+1 ; i ++ , j --)
        boz[i] = j;
    seg.build(boz);
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++){
        int pos = lower_bound(b + 1 , b + m + 2 , a[i]) - b;
        seg.update(-1 , 1 , pos + 1);
        if(i >= m){
            if(i > m)pos = lower_bound(b + 1 , b + m + 2 , a[i - m]) - b,seg.update(1 , 1 , pos + 1);\
            if(seg.query(1, m+2) >= 0)ans++;
        }
    }
    cout << ans;
    return(0);
}