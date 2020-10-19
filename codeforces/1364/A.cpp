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

const ll maxn  = 2e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
int x;
int q;
int lst[maxn];

bool chk(int sz){
    int sum = 0;
    for(int i = 1 ; i <= n ; i  ++){
        sum = (sum + a[i])%x;
        if(i > sz)
            sum = (sum - (a[i - sz])%x + x)%x;
        if(i >= sz)
            if(sum)
                return(1);
    }
    return(0);
}

int32_t main(){
    migmig;
    cin >> q;
    while(q -- ){
        cin >> n >> x;
        for(int i = 1 ; i <= n;  i++)
            cin >> a[i] ,a[i]%=x;
        if(!chk(1)){
            cout << -1 << endl;
            continue;
        }
        if(chk(n)){
            cout << n << endl;
            continue;
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i ++)
            if(a[i])
                ans = max(ans , max(n -  i , i - 1));
        cout << ans << endl;
    }




    return(0);
}