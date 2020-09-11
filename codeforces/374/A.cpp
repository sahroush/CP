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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int x , y;
int a , b;

int f(int x , int y){
    if(x%a)
        return(1e9);
    if(y%b)
        return(1e9);
    if((x/a + y/b)%2)
        return(1e9);
    return(max(x/a , y/b));
}

int32_t main(){
    migmig
    cin >> n >> m;
    cin >> x >> y;
    cin >> a >> b;
    if(((x!= 1 and x!= n) or (y!=1 and y!=m)) and \
        ((x + a > n and x - a < 1) or (y + b > m and y - b < 1)))
        dokme("Poor Inna and pony!")
    int ans = 1e9;
    ans = min(ans , f(x - 1 , y - 1));
    ans = min(ans , f(x - 1 , m - y));
    ans = min(ans , f(n - x , m - y));
    ans = min(ans , f(n - x , y - 1));
    if(ans == 1e9)
        dokme("Poor Inna and pony!");
    cout << ans;
    return(0);
}