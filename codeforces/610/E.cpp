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

const ll maxn  = 2e5+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , k;
string s;
int a[maxn];
int lazy[maxn*4];
int seg[maxn*4][12][12];
int l[maxn*4] , r[maxn*4];

void build(int v = 1 , int l = 1 , int r = n + 1){
    if(r - l == 1){
        ::l[v] = ::r[v] = a[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*v , l , mid);
    build(2*v + 1 , mid , r);
    ::l[v] = ::l[2*v];
    ::r[v] = ::r[2*v+1];
    for(int i = 0 ; i < k ; i ++)
        for(int j = 0 ; j < k ; j ++)
            seg[v][i][j] = seg[2*v][i][j] + seg[2*v + 1][i][j];
    seg[v][::r[2*v]][::l[2*v+1]]++;
}

void shift(int v , int l , int r){
    if(lazy[v] == -1)return;
    ::l[v] = ::r[v] = lazy[v];
    ms(seg[v] , 0);
    seg[v][v[lazy]][lazy[v]] = r - l - 1;
    if(r - l > 1)
        lazy[2*v] = lazy[2*v + 1] = lazy[v];
    lazy[v] = -1;
}

void update(int L , int R ,int x , int v = 1 , int l = 1,  int r = n + 1){
    shift(v , l , r);
    if(r <= L or R <= l)
        return;
    if(L <= l and r <= R){
        lazy[v] = x;
        shift(v , l , r);
        return;
    }
    int mid = (l + r)/2;
    update(L , R , x ,  2*v , l , mid);
    update(L , R , x , 2*v + 1 , mid , r);
    ::l[v] = ::l[2*v];
    ::r[v] = ::r[2*v+1];
    for(int i = 0 ; i < k ; i ++)
        for(int j = 0 ; j < k ; j ++)
            seg[v][i][j] = seg[2*v][i][j] + seg[2*v + 1][i][j];
    seg[v][::r[2*v]][::l[2*v+1]]++;
}

int pos[20];

void solve(string s){
    int ans = 1;
    for(int i = 0 ; i < k ; i ++)
        pos[s[i] - 'a'] = i;
    for(int i = 0 ; i < k ; i ++)
        for(int j = 0 ; j < k ; j ++)
            if(pos[i]>=pos[j])
                ans += seg[1][i][j];
    cout << ans << endl;
}

int32_t main(){
    migmig;
    cin >> n >> m >> k;
    cin >> s;
    ms(lazy , -1);
    for(int i = 1; i <= n ; i ++)
        a[i] = s[i - 1] - 'a';
    build();
    while(m -- ){
        int t;
        cin >> t;
        if(t == 1){
            int l , r;
            string c;
            cin >> l >> r >> c;
            int x = c[0] - 'a';
            update(l , r+1 , x);
        }
        else{
            string s;
            cin >> s;
            shift(1 , 1 , n+1);
            solve(s);
        }
    }
    return(0);
}