/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
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
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , x , pos;
ll ans = 1;

ll fact(ll x){
    ll ans = 1;
    for(ll i = 1  ; i <= x ; i ++)
        ans = (ans * i)%mod;
    return(ans);
}

int32_t main(){
    migmig;
    cin >> n >> x >> pos;
    ll big = n-x;
    ll smol = x - 1;
    int l = 0 , r = n;
    while(l < r){
        int mid;
        mid = (l + r)/2;
        if(mid == pos){
            l = mid + 1;
        }
        if(mid > pos){
            if(!big)
                dokme(0);
            ans = (ans * big)%mod;
            big -- ;
            r = mid;
            
        }
        if(mid < pos){
            if(!smol)
                dokme(0);
            ans = (ans * smol)%mod;
            smol--;
            l = mid + 1;
        }
    }
    if(l > 0 and l-1 == pos)
        ans = (ans * fact(smol + big))%mod;
    else
        ans = 0 ;
    cout << ans;
    return(0);
}