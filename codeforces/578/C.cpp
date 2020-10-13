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

int a[maxn];
int n;

int32_t main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n  ;i ++)
        cin >> a[i];
    ld l = -1e5 , r = 1e5;
    ld mn = 1e9 , mx = -1e9;
    for(int i = 0 ; i < 1000 ; i ++){
        ld mid = (l + r)/2;
        mn = 1e9 , mx = -1e9;
        ld sneg = 0, spos = 0;
        for(int i = 0 ; i < n ; i ++){
            spos += a[i] - mid;
            sneg += a[i] - mid;
            sneg = min(sneg , ld(0));
            spos = max(spos , ld(0));
            mx = max(mx , spos);
            mn = min(mn , sneg);
        }
        if(mx + mn > 0)
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(10) << mx;
    return(0);
}