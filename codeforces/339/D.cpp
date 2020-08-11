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

const ll maxn  = 3e6+ 10;
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
int a[maxn];
int seg[maxn];
int type[maxn];

void build(int v = 1 , int l = 0 ,int  r = n){
    if(r - l == 1){
        seg[v] = a[l];
        return;
    }
    type[v] = 1-type[v/2];
    build(2*v , l , (l + r)/2);
    build(2*v + 1, (l + r)/2 , r);
    if(type[v] == 1)
        seg[v] = seg[2*v] | seg[2*v+1];
    else
        seg[v] = seg[2*v] ^ seg[2*v+1];
}

void update(int pos , int val , int v = 1 , int l = 0 , int r = n){
    if(r - l == 1){
        seg[v] = val;
        return;
    }
    if(pos < (l + r)/2)
        update(pos , val , 2*v , l , (r + l)/2);
    else
        update(pos , val , 2*v+1 , (l+r)/2 , r);
    if(type[v] == 1)
        seg[v] = seg[2*v] | seg[2*v+1];
    else
        seg[v] = seg[2*v] ^ seg[2*v+1];
}

int main(){
    migmig
    cin >> n >> q;
    type[0] = 1 - n%2;
    n = 1 << n;
    for(int i = 0 ; i < n; i ++)
        cin >> a[i];
    build();
    while(q --){
        int pos , val;
        cin >> pos >> val;pos--;
        update(pos , val);
        cout << seg[1] << endl;
    }
    return(0);
}