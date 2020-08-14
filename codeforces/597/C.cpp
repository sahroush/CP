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

const ll maxn  = 8e5 + 10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
ll ans = 0;
ll fen[maxn][15];

ll get(int x , int i){
    ll sum = 0;
    for(;x;x-=x&(-x))
        sum += fen[x][i];
    return(sum);
}

void add(ll x , ll i){
    ll val = 1;
    if(i > 0)
        val = get(x-1 , i-1);
    for(;x < maxn ; x += x&(-x))
        fen[x][i]+=val;
}

void add(ll x){
    for(int i = 0 ; i <= k ; i ++){
        add(x , i);
    }
}

int main(){
    migmig
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++){
        int x;
        cin >> x;
        add(x);
    }
    cout << get(n, k);
    return(0);
}