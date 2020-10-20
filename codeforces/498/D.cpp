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

int n;
int a[maxn];
int seg[maxn*4][70];
int q;


void build(int v = 1 , int l = 1 , int r = n + 1){
    if(r - l == 1){
        for(int i = 0 ; i < 60 ; i ++)
            seg[v][i] = 1 + (i%a[l] == 0);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v , l , mid);
    build(2 * v + 1 , mid , r);
    for(int i = 0 ; i < 60 ; i ++)
        seg[v][i] = seg[2*v][i] + seg[2*v+1][(i + seg[2*v][i]) % 60];
}

void update(int pos , int x , int v = 1 , int l = 1 , int r = n + 1){
    if(r - l == 1){
        a[l] = x;
        for(int i = 0 ; i < 60 ; i ++)
            seg[v][i] = 1 + (i%a[l] == 0);
        return;
    }
    int mid = (l + r) / 2;
    if(pos < mid)
        update(pos,  x , 2*v , l , mid);
    else
        update(pos , x , 2*v + 1, mid , r);
    for(int i = 0 ; i < 60 ; i ++)
        seg[v][i] = seg[2*v][i] + seg[2*v+1][(i + seg[2*v][i]) % 60];
}

int t = 0;

void query(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
    if(r <= L or R <= l){
        return;
    }
    if(L <= l and r <= R){
        t += seg[v][t%60];
        return;
    }
    int mid = (l + r)/2;
    query(L , R , 2*v , l , mid);
    query(L , R , 2*v + 1 , mid , r);
}

int32_t main(){
    migmig;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    build();
    cin >> q;
    while(q -- ){
        string t;
        int x , y;
        cin >> t;
        cin >> x >> y;
        if(t == "A"){
            ::t = 0;
            query(x , y);
            cout << ::t << endl;
        }
        else{
            update(x , y);
        }
    }
    return(0);
}