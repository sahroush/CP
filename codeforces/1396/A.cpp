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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n;
ll a[maxn];
ll pos[maxn];

int32_t main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    if(n == 1){
        cout << 1 << ' ' << 1 << endl;
        cout << -a[0] << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        return(0);
    }
    cout << 1 << ' ' << 1 << endl;
    cout << -a[0] << endl;
    cout << 2 << ' ' << n << endl;
    a[0] = 0;
    for(int i = 0 ; i < n ; i ++)
        pos[((n-1) * i) % n] = (n-1)*i;
    for(int i = 1 ; i < n ; i ++)
        cout << pos[n - (a[i]%n + n*10LL)%n] << ' ', a[i] +=  pos[n - (a[i]%n + n*10LL)%n];
    cout << endl << 1 << ' ' << n << endl;
    for(int i = 0 ; i < n ; i ++)
        cout << -(a[i]) << ' ';
    return(0);
}