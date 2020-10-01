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

const ll maxn  = 1e6+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
unordered_map < int  , int > l , r;
int fen[maxn];

void add(int x , int pos){
    for(pos += 5 ; pos < maxn ; pos += pos & -pos)
        fen[pos] += x;
}

int get(int pos){
    int sum = 0;
    for(pos += 5 ; pos ; pos -= pos & -pos)
        sum += fen[pos];
    return(sum);
}

int get(int l , int r){
    return(get(r) - get(l - 1));
}


int32_t main(){
    migmig
    cin >> n;
    r.reserve(256);
    l.reserve(256);
    r.max_load_factor(0.25);
    l.max_load_factor(0.25);
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i], l[a[i]] ++, add(1 , l[a[i]]);
    ll ans = 0;
    for(int i = n - 1 ; i >= 0 ; i --){
        add(-1 , l[a[i]]);
        l[a[i]] --;
        r[a[i]] ++;
        ans += get(r[a[i]] + 1 , maxn - 100);
    }
    cout << ans;
    return(0);
}