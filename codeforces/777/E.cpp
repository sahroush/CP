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

const ll maxn  = 2e5 + 100;
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
pair < pii , ll > a[maxn];
ll fen[maxn];
vector < int > vec;

void add(ll x , int pos){
    for(pos+=5;pos < maxn;pos+=pos&(-pos))
        fen[pos] = max(fen[pos] , x);
}

ll get(int pos){
    ll ans = 0;
    for(pos+=5;pos;pos-=pos&(-pos))
        ans = max(ans , fen[pos]);
    return(ans);
}

void update(int l ,int r , ll val){
    add(get(r-1) + val , l);
}

int32_t main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i].first.first >> a[i].first.second >> a[i].second, swap(a[i].first.first , a[i].first.second);
    sort(a , a + n);
    reverse(a , a + n);
    for(int i = 0 ; i < n ; i ++)
        vec.pb(a[i].first.first),vec.pb(a[i].first.second);
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin() , vec.end()) - vec.begin());
    for(int i = 0 ; i < n ; i ++)
        a[i].first.first  = lower_bound(vec.begin() , vec.end() , a[i].first.first) - vec.begin(),
        a[i].first.second = lower_bound(vec.begin() , vec.end() , a[i].first.second) - vec.begin();
    for(int i = 0; i < n ; i ++)
        update(a[i].first.second,a[i].first.first , a[i].second);
    cout << get(maxn - 10);
    return(0);
}