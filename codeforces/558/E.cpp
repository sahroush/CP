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

int a[maxn];
string s;
int n , q;

struct segment{
    int seg[maxn*4];
    int lazy[maxn*4];
    void init(){for(int i = 0 ; i < maxn*4 ; i ++)lazy[i]=-1;}
    void build(int v = 1 ,int l = 1 ,int r = maxn){
        if(v==1)init();
        if(r - l == 1){
            seg[v] = a[l];
            return;
        }
        build((v << 1) , l , (l + r) >> 1);
        build((v << 1)|1 , (l + r) >> 1 , r);
        seg[v] = seg[(v << 1)] + seg[(v << 1)|1];
    }
    void prog(int v , int l , int r){
        if(lazy[v] == -1)
            return;
        seg[v] = (r-l)*lazy[v];
        if(r-l > 1)
            lazy[(v << 1)] = lazy[v] , lazy[(v << 1)|1]=lazy[v];
        lazy[v] = -1;
    }
    void update (int L , int R ,int val ,int v = 1 , int l = 1 , int r = maxn){
        if(l >= R or r <= L)
            return;
        prog(v , l , r);
        if(L <= l and r <= R ){
            lazy[v] = val;
            return;
        }
        update(L , R , val , (v << 1) , l , (l + r) >> 1);
        update(L , R , val , (v << 1) | 1 , (l + r) >> 1 , r);
        prog((v << 1) , l , (l + r) >> 1);
        prog((v << 1) | 1 , (l + r) >> 1 , r);
        seg[v] = seg[(v << 1)] + seg[(v << 1)|1];
    }
    int query(int L , int R , int v = 1, int l = 1 , int r = maxn){
        prog(v , l , r);
        if(l >= R or r <= L)
            return(0);
        if(L <= l and r <= R )
            return(seg[v]);
        int ans = 0;
        ans += query(L , R , (v << 1) , l , (l + r) >> 1);
        ans += query(L , R , (v << 1) | 1 , (l + r) >> 1 , r);
        return(ans);
    }
}seg[26];

int cnt[26];

int main(){
    migmig
    cin >> n >> q;
    cin >> s;
    for(int i = 0 ; i < 26 ; i ++){
        ms(a , 0);
        for(int j = 0 ; j < n ; j ++ ){
            a[j+1] = ((s[j] - 'a')==i);
        }
        seg[i].build();
    }
    while(q -- ){
        int l , r , k;
        cin >> l >> r >> k;
        r++;
        ms(cnt , 0);
        for(int i = 0 ; i < 26 ; i ++){
            cnt[i] = seg[i].query(l , r);
            seg[i].update(l , r , 0);
        }
        if(k){
            for(int i = 0 ; i < 26 ; i ++){
                seg[i].update(l , l + cnt[i] , 1);
                l += cnt[i];
            }
        }
        else{
            for(int i = 25 ; i >= 0 ; i --){
                seg[i].update(l , l + cnt[i] , 1);
                l += cnt[i];
            }
        }
    }
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 0 ; j < 26 ; j ++)
            if(seg[j].query(i , i + 1)){
                cout << char('a' + j);
                break;
            }
    return(0);
}