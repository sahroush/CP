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

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
int a[maxn];
int diff[maxn];
int ans = 0;

struct BIT{
    int fen[maxn];
    void add(int x , int pos){
        for( ; pos < maxn ; pos += pos & -pos)
            fen[pos] += x;
    }
    void add(int x , int l , int r){
        add(x , l);
        add(-x , r+1);
    }
    int get(int pos){
        int ans = 0;
        for(; pos ; pos -= pos & -pos)
            ans += fen[pos];
        return(ans);
    }
    int get(int l , int r){
        return(get(r) - get(l - 1));
    }
};
BIT fen;

struct segment{
    int seg[maxn*4];
    int peak[maxn*4];
    int valley[maxn*4];
    segment(int x){
        ms(seg , x);
        ms(valley , x);
    }
    void build(int v = 1 , int l = 1 , int r = n + 1){
        if(r - l == 1){
            if(l == 1 or l == n)return;
            if(a[l - 1] > a[l] and a[l] < a[l + 1])
                valley[v] = l;
            else
                seg[v] = max(a[l + 1] - a[l] , a[l - 1] - a[l]);
            if(a[l - 1] <= a[l] and a[l] >= a[l + 1])
                peak[v] = l;
            return;
        }
        int mid = (l + r)/2;
        build(2*v , l , mid);
        build(2*v + 1, mid , r);
        seg[v] = min(seg[2*v] , seg[2*v + 1]);
        peak[v] = max(peak[2*v] , peak[2*v + 1]);
        valley[v] = min(valley[2*v] , valley[2*v + 1]);
    } 
    void update(int pos , int x , int st , int v = 1 , int l = 1 , int r = n + 1){
        if(r - l == 1){
            if(st == 1)
                peak[v] = x;
            if(st == 2)
                valley[v] = x;
            if(st == 3)
                seg[v] = x;
            return;
        }
        int mid = (l + r) / 2;
        if(pos < mid)
            update(pos , x , st , 2*v , l , mid);
        else
            update(pos , x , st , 2*v + 1 , mid , r);
        seg[v] = min(seg[2*v] , seg[2*v + 1]);
        peak[v] = max(peak[2*v] , peak[2*v + 1]);
        valley[v] = min(valley[2*v] , valley[2*v + 1]);
    }
    int pek(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
        if(r <= L or R <= l)
            return(0);
        if(L <= l and r <= R)
            return(peak[v]);
        int mid = (l + r)/2;
        return(max(pek(L , R , 2*v , l , mid) , pek(L , R , 2*v + 1 , mid , r)));
    }
    int query(int L ,int R , int v = 1 , int l = 1 , int r = n + 1){
        if(r <= L or R <= l)
            return(seg[n*4 + 1]);
        if(L <= l and r <= R)
            return(seg[v]);
        int mid = (l + r)/2;
        return(min(query(L , R , 2*v , l , mid) , query(L , R , 2*v + 1 , mid , r)));
    }
    int valy(int L ,int R , int v = 1 , int l = 1 , int r = n + 1){
        if(r <= L or R <= l)
            return(seg[n*4 + 1]);
        if(L <= l and r <= R)
            return(valley[v]);
        int mid = (l + r)/2;
        return(min(valy(L , R , 2*v , l , mid) , valy(L , R , 2*v + 1 , mid , r)));
    }
    
    int solve(int l , int r , int x){
        if(pek(l , r))
            return(2 * x);
        int ans = -seg[n*4 + 1];
        int res = query(l , r);
        if(res < seg[n*4 + 1])
            ans = max(0LL , (x - res) * 2);
        res = valy(l , r);
        if(res < seg[n*4 + 1])
            ans = max(ans , ((x < diff[res]) ? -x : x - diff[res] * 2) +
             ((x < diff[res - 1]) ? -x : x - diff[res-1]*2));
        if(l == 1)
            ans = max(ans , abs(fen.get(1) + x - fen.get(2)) - diff[1]);
        if(r == n+1)
            ans = max(ans , abs(fen.get(n) + x - fen.get(n - 1)) - diff[n - 1]);
        return(ans);
    }
};
segment seg(63);

void calc(int pos){
    if(pos < n){
        int b = fen.get(pos);
        int c = fen.get(pos + 1);
        if(pos > 1){
            int a = fen.get(pos - 1); 
            if(a <= b and b >= c){
                seg.update(pos , pos , 1);
            }
            else{
                seg.update(pos , 0 , 1);
            }
            if(a > b and b < c){
                seg.update(pos , pos , 2);
                seg.update(pos , seg.seg[n*4 + 1] , 3);
            }
            else{
                seg.update(pos , seg.seg[n*4 + 1] , 2);
                seg.update(pos , max(c - b , a - b) , 3);
            }
        }
        ans += abs(b - c) - diff[pos];
        diff[pos] = abs(b - c);
    }
}

void update(int l , int r , int x){
    fen.add(x , l , r);
    calc(l);
    if(l > 1)calc(l - 1);
    if(r != l)calc(r);
    if(r < n)calc(r + 1);
}

int32_t main(){
    migmig;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i] , fen.add(a[i] , i , i);
    for(int i = 1 ; i < n ; i ++)
        diff[i] = abs(a[i] - a[i + 1]),
        ans += diff[i];
    seg.build();
    cin >> q;
    while(q -- ){
        int t , l , r , x;
        cin >> t >> l >> r >> x;
        if(t == 1)
            cout << ans + seg.solve(l , r+1 , x) << endl;
        else
            update(l , r , x);
    }
    return(0);
}