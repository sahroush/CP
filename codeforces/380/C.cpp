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

const ll maxn  = 1e6 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s;
int q;
int ans[maxn*4];
int o[maxn*4];
int c[maxn*4];
int n;

#define lc(v) 2*v
#define rc(v) 2*v + 1

struct e{
    int a , b , c;
    e(int aa ,int bb ,int cc):
        a(aa) , b(bb) , c(cc){}
};

void build(int v = 1 , int l = 1 , int r = n+1){
    if(r - l == 1){
        if(s[l] == '(') o[v] = 1;
        else c[v] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 *v , l , mid);
    build(2*v + 1 , mid , r);
    int mn = min(o[lc(v)] , c[rc(v)]);
    c[v] = c[lc(v)] + c[rc(v)] - mn;
    o[v] = o[lc(v)] + o[rc(v)] - mn;
    ans[v] = ans[lc(v)] + ans[rc(v)] + mn;
}

e calc(e a , e b){
    int mn = min(a.a , b.b);
    return(e(a.a + b.a - mn , a.b + b.b - mn , a.c + b.c + mn));
}   

e query(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
    if(v == 1) R ++;
    if(r <= L or R <= l)
        return(e(0 , 0 , 0));
    if(L <= l and r <= R)
        return(e(o[v] , c[v] , ans[v]));
    int mid = (l + r) / 2;
    return(calc(query(L , R , lc(v) , l , mid) , query(L , R , rc(v) , mid , r)));
}

int32_t main(){
    migmig
    cin >> s;
    n = s.size();
    s = "%" + s;
    build();
    cin >> q;
    //mo ham mishe zad
    while(q -- ){
        int l , r;
        cin >> l >> r;
        cout << query(l , r).c * 2 << endl;
    }
    return(0);
}