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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int seg[maxn] , a[maxn];
int q , l , r;
vector < pii > vec;

void calc(int v){
    seg[v] = __gcd(seg[2*v+1] , seg[2*v + 2]);
}
void build(int v = 0 ,int l = 1 ,int r = n){
    if(l == r){seg[v] = a[l] ; return;}
    int mid = (l + r)/2;
    build(2*v + 1 , l , mid);
    build(2*v + 2 , mid+1 , r);
    calc(v);
}
int query(int v = 0 , int l = 1 , int r = n){
    if(l >= ::l and r<=::r)
        return(seg[v]);
    int ans = 0;
    int mid = (l + r)/2;
    if(::l <= mid)
        ans = query(2*v + 1, l , mid);
    if(::r >= mid+1)
        (ans == 0)?(ans = query(2*v + 2, mid+1 , r)) : (ans = __gcd(ans , query(2*v + 2, mid+1 , r)));
    return(ans);
}

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i] , vec.pb({a[i] , i});
    sort(vec.begin() , vec.end());
    build();
    cin >> q;
    while(q--){
        cin >> l >> r;
        int gcd = query();
        cout << r - l + 1 - abs(lower_bound(vec.begin() , vec.end() , pii(gcd , l)) - upper_bound(vec.begin() , vec.end() , pii(gcd , r))) << endl;
    }
    return(0);
}