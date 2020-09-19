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

const ll maxn  = 5e5+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int nxt[maxn][30];

int32_t main(){
    migmig
    cin >> n >> m;
    for(int i = 0 ; i < maxn ; i ++)
        nxt[i][0] = -1;
    for(int i = 0 ; i < n ; i ++){
        int l , r;
        cin >> l >> r;
        nxt[l][0] = max(nxt[l][0] , r);
    }
    for(int i = 1 ; i < maxn ; i ++)
        nxt[i][0] = ((max(nxt[i-1][0] , nxt[i][0]) > i)?
        (max(nxt[i-1][0] , nxt[i][0])) : -1);
    for(int i = 1 ; i < 20 ; i ++)
        for(int j = 0 ; j < maxn ; j ++)
            nxt[j][i] = ((nxt[j][i-1] > -1)?nxt[nxt[j][i-1]][i-1] : -1);
    while(m --){
        int l , r;
        cin >> l >> r;
        int ans = 0;
        int pos = l;
        for(int i = 19 ; i >= 0 ; i --)
            if(nxt[pos][i] > 0 and nxt[pos][i]<r)
                pos = nxt[pos][i],
                ans += 1 << i;
        ans ++;
        for(int i = 19 ; i >= 0 ; i --){
            if(ans & (1 << i))
                l = nxt[l][i];
        }
        if(l < r)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return(0);
}