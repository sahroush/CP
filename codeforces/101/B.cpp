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
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int m;
vector < int > vec;
pii a[maxn];
int fen[maxn];

int comp(int x){
    return(lower_bound(vec.begin(),
    vec.end(), x) - vec.begin() + 1);
}

void add(int x , int pos){
    for(pos += 5;pos < maxn ; pos += pos & -pos)
        fen[pos] = (fen[pos] + x)%mod;
}

int get(int pos){
    int ans = 0;
    for(pos += 5;pos; pos -= pos & -pos)
        ans = (ans + fen[pos])%mod;
    return(ans);
}

int get(int l , int r){
    return(((get(r) - get(l-1))%mod + mod)%mod);
}

int32_t main(){
    migmig
    cin >> n >> m;
    vec.pb(n);
    vec.pb(0);
    for(int i = 0 ; i < m ; i ++)
        cin >> a[i].first >> a[i].second,
        vec.pb(a[i].first) , vec.pb(a[i].second);
    sort(vec.begin() , vec.end());
    vec.resize(unique(vec.begin() , vec.end()) - vec.begin());
    for(int i = 0 ; i < m ; i ++)
        a[i].first = comp(a[i].first),
        a[i].second = comp(a[i].second);
    n = comp(n);
    for(int i = 0 ; i < m ; i ++)
        swap(a[i].first , a[i].second);
    sort(a , a + m);
    for(int i = 0 ; i < m ; i ++)
        swap(a[i].first , a[i].second);
    add(1 , comp(0));
    for(int i = 0 ; i < m ; i ++){
        add(get(a[i].first , a[i].second - 1 ), a[i].second);
    }
    cout << get(n , n);
    return(0);
}