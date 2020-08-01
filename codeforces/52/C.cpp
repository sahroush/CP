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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
int seg[maxn] , a[maxn];
int lazy[maxn];
int l  = 0, r = 0 , val = 0;

void calc(int v){
    seg[v] = min(seg[2*v + 1] , seg[2*v + 2]);
}
void build(int v = 0 ,int l = 1 ,int r = n ){
    if(l == r){
        seg[v] = a[l];return;}
    int mid = (l + r)/2;
    build(2*v + 1 , l , mid);
    build(2*v + 2 , mid + 1 , r);
    calc(v);
}
void prog(int v , int l , int r){
    if(lazy[v] == 0)
        return;
    seg[v]+=lazy[v];
    if(l < r)
        lazy[2*v+1]+=lazy[v] , lazy[2*v + 2]+=lazy[v];
    lazy[v] = 0;
}
void update(int v = 0 , int l = 1 , int r = n){
    prog(v , l , r);
    if(l>=::l and r<=::r){
        lazy[v]+=val;return;}
    int mid = (l + r)/2;
    if(::l <= mid)
        update(2*v+1 , l , mid);
    if(::r >= mid+1)
        update(2*v+2 , mid+1 , r);
    prog(2*v+1 , l , mid);
    prog(2*v+2 , mid+1 , r);
    calc(v);
}
int query(int v = 0 , int l = 1 , int r = n){
    prog(v , l , r);
    if(l>=::l and r<=::r)
        return(seg[v]);
    int ans = 1e9;
    int mid = (l + r)/2;
    if(::l <= mid)
        ans = min(ans , query(2*v+1 , l , mid));
    if(::r >= mid+1)
        ans = min(ans , query(2*v+2 , mid+1 , r));
    return(ans);
}
int32_t main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++ )
        cin >> a[i];
    build();
    cin >> q;
    while(q -- ){
        cin >> l >> r;
        l ++ , r++;
        if(cin.peek()!='\n'){
            cin >> val;
            if(l <= r){
                update();
                continue;
            }
            pii a = { 1 , r };
            pii b = { l , n };
            l = a.first , r = a.second;
            update();
            l = b.first , r = b.second;
            update();
        }
        else{
            if(l <= r ){
                cout << query() << endl;
                continue;
            }
            int ans = 1e9;
            pii a = { 1 , r };
            pii b = { l , n };
            l = a.first , r = a.second;
            ans = min(ans , query());
            l = b.first , r = b.second;
            ans = min(ans , query());
            cout << ans << endl;
        }
    }
    return(0);
}