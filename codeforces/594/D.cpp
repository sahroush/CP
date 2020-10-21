/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
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
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll a[maxn];
int t;
int ans[maxn];
vector < int > vec[maxn];
ll inv[maxn];
ll val[maxn] , lav[maxn];
int orz[maxn];

const int sq = 750;

struct tr{
    int l  , r , i;
    friend bool operator < (tr &a , tr &b){
        if(a.l/sq == b.l/sq){
            if((a.l/sq)%2)return(a.r > b.r);
            else return(a.r < b.r);
        }
        return(a.l < b.l);
    }
};

tr q[maxn];

ll p = 1;
int cnt[maxn];

inline void add(int x){
    p = (p * a[x])%mod;
    auto &v = vec[x];
    for(auto &y : v){
        cnt[y]++;
        if(cnt[y] == 1){
            p = (p * val[y])%mod;
        }
    }
}

inline void remove(int x){
    p = (p * inv[a[x]])%mod;
    auto &v = vec[x];
    for(auto &y : v){
        cnt[y]--;
        if(cnt[y] == 0){
            p = p * lav[y]%mod;
        }
    }
}

int32_t main(){
    migmig;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> i[a];
    for(int i = 0 ; i < maxn ; i ++)
        inv[i] = pw(i , mod - 2);
    for(ll i = 1 ; i < maxn ; i ++)
        val[i] = (i - 1)*inv[i] % mod , lav[i] = inv[i - 1] * i % mod;
    for(int i = 2 ; i < maxn ; i += 2)
        orz[i] = 2;
    for(int i = 3 ; i < maxn ; i +=2)
        if(!orz[i])
            for(int j = i ; j < maxn ; j +=i)
                orz[j] = i;
    for(int i = 1 ; i <= n ; i ++){
        vec[i].reserve(32);
        int cur = a[i];
        while(cur!=1){
            vec[i].pb(orz[cur]);
            while(cur % vec[i].back() == 0)
                cur/=vec[i].back();
        }
    }
    cin >> t;
    for(int i = 1 ; i <= t ; i ++)
        cin >> q[i].l >> q[i].r , q[i].i = i;
    sort(q + 1 , q + t + 1);
    int l = 1 , r = 1;
    add(1);
    for(int i = 1 ; i <= t ; i ++){
        while(l < q[i].l)
            remove(l++);
        while(r < q[i].r)
            add(++r);
        while(r > q[i].r)
            remove(r -- );
        while(l > q[i].l)
            add(--l);
        ans[q[i].i] = p;
    }
    for(int i = 1 ; i <= t ; i ++)
        cout << ans[i] << endl;
    return(0);
}