//*
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

const ll maxn  = 3e5+10;
const ll mod =1e9+9;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q , cnt = 0, prt[maxn];
int a[maxn], fib[maxn], prtfib[maxn], stk[maxn];
vector < pii > st;

int get(int l , int r){
    int ans = ((prt[r] - prt[l-1])%mod + mod )%mod;
    for(auto [i , j] : st){
        if(i > r or j < l)continue;
        int start = ((l > i)?l : i) , end = ((r > j)?j : r);
        ans = (ans + (((prtfib[end-i+1] - prtfib[start - i])%mod + mod)%mod))%mod;
    }
    return(ans);
}
void update(){
    ms(stk , 0);
    for(auto [l , r] : st){
        stk[l] = (stk[l] + 1)%mod;
        stk[r+1] = ((stk[r+1] - fib[r - l + 2])%mod + mod)%mod;
        stk[r+2] = ((stk[r+2] - fib[r - l + 1])%mod + mod)%mod;
    }
    st.clear();
    a[1] = (a[1] + stk[1])%mod;
    for(int i = 2 ; i <= n ; i ++)
        stk[i] = ((stk[i-1] + stk[i-2])%mod + stk[i])%mod , a[i] = (a[i] + stk[i])%mod;
    ms(prt , 0);
    for(int i = 1 ; i <= n ; i ++ ) prt[i] = (prt[i-1] + a[i])%mod;
}

int main(){
    migmig
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i ++ ) cin >> a[i];
    for(int i = 1 ; i <= n ; i ++ ) prt[i] = (prt[i-1] + a[i])%mod;
    prtfib[1] = fib[1] = 1;
    for(int i = 2 ; i < maxn ; i ++)
        fib[i] = (fib[i-1] + fib[i-2])%mod , prtfib[i] = (prtfib[i-1]+fib[i])%mod;
    while(q -- ){
        int t , l , r;
        cin >> t >> l >> r;
        if(t%2){
            st.pb({l , r});
        }
        else{
            cout << get(l , r) << endl;
        }
        if((++cnt)%600 == 0)update();
    }
    return(0);
}