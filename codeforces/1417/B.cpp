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

int q;
int n , t;
int a[maxn];
int mark[maxn];

int32_t main(){
    migmig
    cin >> q;
    while(q --){
        cin >> n >> t;
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i],mark[i] = 0;
        int cur = 0;
        for(int i = 0 ; i < n ; i ++){
            if(ll(a[i])*2 == t){
                mark[i] = cur;
                cur = 1- cur;
            }
            else if(ll(a[i])*2 < t){
                mark[i] = 0;
            }
            else
                mark[i] = 1;
            cout << mark[i] << ' ';
        }
        cout << endl;
    }




    return(0);
}