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
int a[maxn] , b[maxn];
int x;

int s(int i){
    int sum = 0;
    int mn = 1e9;
    for(int j = 1 ; j <= m ; j ++){
            sum += b[j];
            if(j > i)
                sum -= b[j - i];
            if(j>=i)mn = min(mn , sum);
        }
   return(mn);
}

int32_t main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 1 ; i <= m ; i ++)
        cin >> b[i];
    cin >> x;
    int mx = 0;
    for(int i = 1 ; i <= n ; i ++){
        int sum = 0;
        int mn = 1e9;
        for(int j = 1 ; j <= n ; j ++){
            sum += a[j];
            if(j > i)
                sum -= a[j - i];
            if(j>=i)mn = min(mn , sum);
        }
        int l = 0 , r = m+1;
        while(r-l > 1){
            int mid = (l + r)/2;
            if(s(mid) * mn <= x)
                l = mid;
            else
                r = mid;
        }
        mx = max(mx , l * i);
    }
    cout << mx;
    return(0);
}