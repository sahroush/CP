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

const ll maxn  = 1e6 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int fact[maxn];
int inv[maxn];
int fen[maxn];
int p[maxn] , n;
int sum;

int f(int k){
    return((((fact[k] * k)%mod * (k - 1))%mod * pw(4 , mod - 2)) %mod);
}

void add(int x , int pos){
    for( ; pos < maxn ; pos += pos & -pos)
        fen[pos] += x;
}

int get(int pos){
    int ans = 0;
    for( ; pos ; pos -= pos & -pos)
        ans += fen[pos];
    return(ans);
}

int32_t main(){
    migmig
    fact[0] = inv[0] = 1;
    for(int i = 1 ; i < maxn ; i ++)
        fact[i] = (fact[i-1] * i)%mod , inv[i] = pw(fact[i] , mod - 2);
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> p[i] , add(1 , i);
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++){
        add(-1 , p[i]);
        ans = (ans + ((get(p[i]) * sum)%mod * fact[n-i])%mod)%mod;
        ans = (ans + (get(p[i]) * f(n - i))%mod )%mod;
        ans = (ans + (((fact[n - i ] * get(p[i]))%mod * (get(p[i]) - 1) % mod) * pw(2 , mod - 2))%mod) %mod;
        sum += get(p[i]);
    }
    cout << (ans + sum)%mod;
    return(0);
}