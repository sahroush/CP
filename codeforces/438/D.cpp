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

const ll maxn  = 1e5+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
ll a[maxn];

struct fenwick{
    ll fen[maxn];
    
    void add(ll x , int pos){   
        for(;pos < maxn;pos+=pos&(-pos))
            fen[pos] += x;
    }

    ll sum(int pos){
        ll sum = 0;
        for(;pos;pos-=pos&(-pos))
            sum+=fen[pos];
        return(sum);
    }
}fen;

struct segment{
    int seg[maxn*4];
    void build(int v = 1 , int l = 1, int r = maxn){
        if(r - l == 1){
            seg[v] = l;
            fen.add(a[l] , l);
            return;
        }
        int mid = (l + r)/2;
        build(2 * v , l , mid);
        build(2*v + 1 , mid , r);
        if(a[seg[2*v]] > a[seg[2*v+1]]){
            seg[v] = seg[2*v];
        }
        else{
            seg[v] = seg[2*v + 1];
        }
    }
    void update(int pos , int val , int v = 1 , int l = 1, int r = maxn){
        if(pos < l or r <= pos)
            return;
        if(r - l == 1){
            fen.add(val - a[l] , l);
            seg[v] = l;
            a[l] = val;
            return;
        }
        int mid = (r + l) / 2;
        update(pos , val , 2*v , l , mid);
        update(pos , val , 2*v + 1,  mid  , r);
        if(a[seg[2*v]] > a[seg[2*v+1]])
            seg[v] = seg[2*v];
        else
            seg[v] = seg[2*v + 1];
    }
    int query(int L , int R , int v = 1, int l = 1, int r = maxn){
        if(r <= L or R <= l)
            return(0);
        if(L <= l and r <= R)
            return(seg[v]);
        int mid = (r + l) >> 1;
        int f = query(L , R , 2*v , l , mid);
        int s = query(L , R , 2*v + 1 , mid , r);
        if(a[f] > a[s])
            return(f);
        return(s);
    }
}seg;

int main(){
    migmig
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    seg.build();
    while(q -- ){
        int t;
        cin >> t;
        if(t == 1){ //print
            int l , r;
            cin >> l >> r;
            cout << fen.sum(r) - fen.sum(l-1) << endl;
        }
        if(t == 2){ // mod
            int l , r, x;
            cin >> l >> r >> x;
            r++;
            while(a[seg.query(l , r)] >= x)
                seg.update(seg.query(l , r) , a[seg.query(l , r)] % x);
        }
        if(t == 3){ // change
            int k , x;
            cin >> k >> x;
            seg.update(k , x);
        }
    }
    return(0);
}