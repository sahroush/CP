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

const ll maxn  = 1e5+10;
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
int sq = 400;
struct com{
    bool isfucked = 1;
    ll val = 0;
    int color = 0;
    ll size  = 0;
    ll sum = 0;
    int l = 1e9 , r = 0;
}comp[1000];
ll val[maxn];
ll col[maxn];

inline void unfuck(int i, ll x){
    if(comp[i].isfucked){
        comp[i].isfucked = 0;
        comp[i].color = x;
        for(int j = comp[i].l ; j <= comp[i].r ; j ++){
            val[j] += abs(col[j] - x);
            comp[i].sum += abs(col[j] - x);
            col[j] = x;
        }
    }
    else{
        comp[i].sum += abs(x - comp[i].color) * comp[i].size;
        comp[i].val += abs(x - comp[i].color);
        comp[i].color = x;
    }
}

inline void fuck(int i, int l , int r , ll x){
    l = max(l , comp[i].l) , r = min(r ,comp[i].r);
    if(comp[i].isfucked){
        for(int j = l ; j <= r ; j ++){
            val[j] += abs(col[j] - x);
            comp[i].sum += abs(col[j] - x);
            col[j] = x;
        }
    }
    else{
        comp[i].isfucked = 1;
        for(int j = comp[i].l ; j <= comp[i].r ; j ++){
            val[j] += comp[i].val;
            col[j] = comp[i].color;
            if(j>=l and j <= r){
                val[j] += abs(col[j] - x);
                comp[i].sum += abs(col[j] - x);
                col[j] = x;
            }
        }
        comp[i].val = 0;
        comp[i].color = -1;
    }
}

inline void udp(){
    int l , r;
    ll x;
    cin >> l >> r >> x;
    for(int i = 0 ; i <= n/sq ; i ++){
        if(l > comp[i].r or r < comp[i].l) continue;
        if(l <= comp[i].l and r >= comp[i].r) unfuck(i , x);
        else fuck(i , l , r , x);
    }
}

inline ll get(int i){
    return(comp[i].sum);
}

inline ll getval(int i , int l , int r){
    ll ans = 0;
    l = max(l , comp[i].l) , r = min(r ,comp[i].r);
    for(int j = l ; j <= r ; j ++){
        ans += val[j];
        ans += comp[i].val;
    }
    return(ans);
}

inline ll get(int l , int r){
    ll ans = 0;
    for(int i = 0 ; i <= n/sq ; i ++){
        if(l > comp[i].r or r < comp[i].l) continue;
        if(l <= comp[i].l and r >= comp[i].r) ans += get(i);
        else ans += getval(i , l , r);
    }
    return(ans);
}

int main(){
    migmig
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i ++){
        comp[i/sq].size++;
        comp[i/sq].l = min(comp[i/sq].l , i);
        comp[i/sq].r = i;
        col[i] = i;
    }
    while(q -- ){
        int t;
        cin >> t;
        if(t%2){
            udp();
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << get(l , r) << endl;
        }
    }
    return(0);
}