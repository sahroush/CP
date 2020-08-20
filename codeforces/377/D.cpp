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

const ll maxn  = 3e5 + 10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int l[maxn] , r[maxn] , v[maxn];
vector < int > order[maxn];

struct segment{
    int seg[maxn*4];
    int lazy[maxn*4];
    int ch[maxn*4];
    void build(int v = 1 ,int l = 1 ,int r = maxn){
        if(r - l == 1){
            ch[v] = l;
            return;
        }
        build((v << 1) , l , (l + r) >> 1);
        build((v << 1)|1 , (l + r) >> 1 , r);
        ch[v] = ch[(v << 1)];
    }
    void prog(int v , int l , int r){
        if(lazy[v] == 0)
            return;
        seg[v] += lazy[v];
        if(r-l > 1)
            lazy[(v << 1)] += lazy[v] , lazy[(v << 1)|1] += lazy[v];
        lazy[v] = 0;
    }
    void update (int L , int R ,int val ,int v = 1 , int l = 1 , int r = maxn){
        prog(v , l , r);
        if(l >= R or r <= L)
            return;
        if(L <= l and r <= R ){
            lazy[v] += val;
            prog(v , l , r);
            return;
        }
        update(L , R , val , (v << 1) , l , (l + r) >> 1);
        update(L , R , val , (v << 1) | 1 , (l + r) >> 1 , r);
        seg[v] = max(seg[(v << 1)] , seg[(v << 1)|1]); 
        if(seg[(v << 1)] > seg[(v << 1)|1])
            ch[v] = ch[(v << 1)];
        else
            ch[v] = ch[(v << 1)|1];
    }
    pii query(int L , int R , int v = 1, int l = 1 , int r = maxn){
        prog(v , l , r);
        if(l >= R or r <= L)
            return(pii(0 , v));
        if(L <= l and r <= R )
            return(pii(seg[v] , ch[v]));
        int ans = 0;
        int pos = v;
        if(ans <  query(L , R , (v << 1) , l , (l + r) >> 1).first)
            ans = query(L , R , (v << 1) , l , (l + r) >> 1).first , 
            pos = query(L , R , (v << 1) , l , (l + r) >> 1).second;
        if(ans <  query(L , R , (v << 1) | 1 , (l + r) >> 1 , r).first)
            ans = query(L , R , (v << 1) | 1 , (l + r) >> 1 , r).first , 
            pos = query(L , R , (v << 1) | 1 , (l + r) >> 1 , r).second;
        return(pii(ans , pos));
    }
}seg;

void add(int x){
    for(int i : order[x]){
        int val = i / abs(i);
        seg.update(l[abs(i)] , v[abs(i)]+1 , val);
    }
}

int main(){
    migmig
    seg.build();
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        cin >> l[i] >> v[i] >> r[i];
        order[v[i]].pb(i);
        order[r[i]+1].pb(-i);
    }
    int L , R;
    int mx = 0;
    for(int i = 1; i < maxn ; i ++){
        add(i);
        if(seg.query(1 , maxn).first > mx)
            mx = seg.query(1 , maxn).first,
             L = seg.query(1 , maxn).second , R = i;
    }
    cout << mx << endl;
    for(int i = 1 ; i <= n ; i ++)
        if(l[i]<=L and r[i]>=R and v[i]>=L and v[i]<=R)
            cout << i << ' ';
    return(0);
}