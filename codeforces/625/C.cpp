/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 600;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
int a[600][600];

int32_t main(){
    migmig;
    cin >> n >> k;
    int p1 = 1 , p2 = n*n;
    ll ans = 0;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j < k ; j ++)
			a[i][j] = p1++;
		for(int j = n ; j >= k ; j --)
			a[i][j] = p2--;
		ans += a[i][k];
    }
    cout << ans << endl;
    for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			cout << a[i][j] << ((j == n) ? '\n' : ' ');
    return(0);
}
