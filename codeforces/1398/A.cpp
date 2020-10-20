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
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
vector < pii > vec;

int32_t main(){
    migmig;
    cin >> q;
    while(q -- ){
        cin >> n;
        vec.clear();
        for(int i = 1 ; i <= n ; i ++){
            int x;
            cin >> x;
            vec.pb({x , i});
            
        }
        sort(vec.begin() , vec.end());
        int a = vec[0].first , b = vec[1].first, c = vec[n-1].first;
        if(a + b > c and a + c > b and b + c > a){cout << -1 << endl;
            
        }
        else{
            cout << vec[0].second << ' ' << vec[1].second << ' ' << vec[n - 1].second << endl;
        }
    }
    return(0);
}