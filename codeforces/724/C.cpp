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

int n , k , m;
int x[maxn] , y[maxn] , ans[maxn];
map<int , vector < int > > mp;

bool check(int x , int y){
    //if(x == 0 and y == 0) return(0);
    if(x == 0 and y == m) return(0);
    if(x == n and y == m) return(0);
    if(x == n and y == 0) return(0);
    return(1);
}

int32_t main(){
    migmig
    cin >> n >> m >> k;
    ms(ans , -1);
    for(int i = 0 ; i < k ; i ++){
        cin >> x[i] >> y[i];
        if(x[i]%2 != y[i] % 2) ans[i] = -1;
        mp[x[i] + y[i]].pb(i);
        mp[x[i] - y[i]].pb(i);
    }
    int dx = 1 , dy = 1 , t = 0 , X = 0 , Y = 0;
    while(check(X , Y)){
        int dif;
        if(dx == dy)
            dif = X - Y;
        else
            dif = X + Y;
        for(auto i : mp[dif]){
            if(ans[i] == -1){
                ans[i] = t + (x[i] - X)/dx;
            }
        }
        int d = 1e9;
        if(dx == -1)
            d = X;
        else
            d = n-X;
        if(dy == -1)
            d = min(d , Y);
        else
            d = min(d , m-Y);
        X += d * dx;
        Y += d*dy;
        if(X == 0 or X == n)
            dx*=-1;
        else
            dy*=-1;
        t += d;
    }
    for(int i = 0 ; i < k ; i ++)   
        cout << ans[i] << endl;
    return(0);
}