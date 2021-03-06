//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , a , b , c;

int32_t main(){
    migmig;
    cin >> n >> a >> b >> c;
    if(n < b)
        dokme(n/a);
    ll ans = 0;
    ll x = n/a;
    ll sz = b - c;
    ll bz = b + sz;
    ans = n/sz - bz/sz;
    n = n - ans * sz;
    while(n >= b){
        ll res = n/b;
        ans += res;
        n %= b;
        n += c * res;
    }
    cout << max(x , ans + n / a); 
    return(0);
}
