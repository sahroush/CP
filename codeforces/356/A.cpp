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

const ll maxn  = 3e5+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int ans[maxn];
int n , m;
int lazy[maxn*4];

void shift(int v , int l , int r){
    if(r - l == 1){
        if(!ans[l])ans[l] = lazy[v];
        return;
    }
    if(!lazy[2*v])lazy[2*v] = lazy[v];
    if(!lazy[2*v+1])lazy[2*v + 1] = lazy[v];
    lazy[v] = 0;
}   

void update(int x , int L , int R , int v = 1 , int l = 1 , int r = maxn){
    shift(v , l , r);
    if(l >= R or L >= r)
        return;
    if(L <= l and r <= R){
        lazy[v] = x;
        shift(v ,l , r);
        return;
    }
    int mid = (l + r)/2;
    update(x , L , R , 2*v , l , mid);
    update(x , L , R , 2*v + 1 , mid , r);
}

int get(int pos , int  v = 1 , int  l = 1 , int r = maxn){
    shift(v , l , r);
    if(r - l == 1)
        return(ans[l]);
    int mid = (l + r) / 2;
    if(pos < mid)
        return(get(pos , 2*v , l , mid));
    return(get(pos , 2*v + 1, mid , r));
}

int32_t main(){
    migmig
    cin >> n >> m;
    while(m -- ){
        int l , r , w;
        cin >> l >> r >> w;
        update(w , l , w);
        update(w , w+1 , r+1);
    }
    for(int i = 1 ; i <= n ; i ++)
        cout << get(i) << ' ';
    return(0);
}