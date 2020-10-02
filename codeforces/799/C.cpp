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

int n , c , d;
int C[maxn] , D[maxn];

void add(int x , int pos , int (&fen)[maxn]){
    for(pos += 5 ; pos < maxn ; pos += pos & - pos)
        fen[pos] = max(fen[pos] , x);
}

int get(int pos , int (&fen)[maxn]){
    if(pos < 0)return(0);
    int ans = 0;
    for(pos += 5 ; pos  ; pos -= pos & - pos)
        ans = max(ans , fen[pos]);
    return(ans);
}

int32_t main(){
    migmig
    cin >> n >> c >> d;
    int ans = 0;
    while(n --){
        int v , p;
        string t;
        cin >> v >> p >> t;
        if(t == "D"){
            if(p > d)continue;
            int res = 0;
            if(get(d - p, D))
                res = max(res , get(d - p , D));
            if(get(c , C))
                res = max(res , get(c , C));
            if(res) 
                ans = max(ans , res + v);
            add(v , p, D);
        }
        else{
            if(p > c)continue;
            int res = 0;
            if(get(d, D))
                res = max(res , get(d, D));
            if(get(c - p, C))
                res = max(res , get(c - p, C));
            if(res) 
                ans = max(ans , res + v);
            add(v , p, C);
        }
    }
    cout << ans;
    return(0);
}