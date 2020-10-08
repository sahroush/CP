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

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
int dp[maxn];
int fen[maxn];

void add(int x , int pos){
    for( ; pos < maxn ; pos += pos & -pos)
        if(a[fen[pos]] <= a[x]) fen[pos] = x;
}

int get(int pos){
    int ans = pos;
    for(; pos ; pos -= pos & -pos)
        if(a[fen[pos]] > a[ans]) ans = fen[pos];
    return(ans);
}

int32_t main(){
    migmig
    cin >> n;
    dp[n + 1] = 1e9;
    for(int i = 1 ; i < n ; i ++)
        cin >> a[i];
    int ans = 1;
    dp[n-1] = 1;
    add(n-1 , n - 1);
    for(int i = n - 2 ; i ; i --){
        int x = get(a[i]);
        dp[i] = dp[x] + n - i - a[i] + x;
        add(i , i);
        ans += dp[i];
    }
    cout << ans;
    return(0);
}