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
int a[maxn];
ll fen[maxn];
ll sum[maxn];

ld f(ld x){
    return(x * (x - 1.0) / 4.0);
}

ld c(ld n){
    return(n * (n - 1.0)/2.0);
}

void add(int x , int pos , ll (&fen)[maxn]){
    for( ; pos < maxn ; pos += pos & -pos)
        fen[pos] += x;
}
 
ld get(int pos , ll (&fen)[maxn]){
    ld ans = 0;
    for(; pos ; pos -= pos & -pos)
        ans += fen[pos];
    return(ans);
}


int32_t main(){
    migmig
    cin >> n;
    for(int i = 1;  i <= n ; i ++)
        cin >> a[i];
    ld s = 0;
    ld inv = 0;
    ld ans = 0;
    for(int i = 1 ; i <= n ; i ++){
        s += ((get(n , sum) - get(a[i] , sum)));
        inv += get(n,fen) - get(a[i] , fen);
        ans += c(i + 1) * (n - i) - s * 2;
        add(1 , a[i] , fen);
        add(i , a[i] , sum);
    }
    for(int i = 1 ; i <= n ; i ++)
        s-=f(i) * (n - i + 1);
    cout << fixed << setprecision(10) << inv + ans / (c(n+1) * 2);
    return(0);
}